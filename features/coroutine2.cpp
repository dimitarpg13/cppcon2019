#include <iostream>
#include <cfloat>
#include <math.h>
#include <cmath>
#include <experimental/coroutine>
using namespace std;

using status_t = int64_t;

using namespace std::experimental;

class promise_return_destroy {
  public:
    auto initial_suspend() noexcept {
        return suspend_never{}; // no suspend after invoke
    }
    auto final_suspend() noexcept {
        return suspend_never{}; // no suspend after return
    }
    void unhandled_exception() noexcept(false) {
        // customize this part
    }
};

class promise_return_preserve {
  public:
    auto initial_suspend() noexcept {
        return suspend_never{}; // no suspend after invoke
    }
    auto final_suspend() noexcept {
        return suspend_always{}; // suspend after return
    }
    void unhandled_exception() noexcept(false) {
        // customize this part
    }
};

class promise_manual_control {
  public:
    auto initial_suspend() noexcept {
        return suspend_always{}; // suspend after invoke
    }
    auto final_suspend() noexcept {
        return suspend_always{}; // suspend after return
    }
    void unhandled_exception() noexcept(false) {
        // customize this part
    }
};
// Async Generator for `for co_await` statement
template <typename T>
class sequence final {
  public:
    class promise_type;
    class iterator;

    using value_type = T;
    using reference = value_type&;
    using pointer = value_type*;

  private:
    static constexpr pointer finished() noexcept {
        return reinterpret_cast<pointer>(0xDEAD);
    }
    static constexpr pointer empty() noexcept {
        return reinterpret_cast<pointer>(0x0000);
    }

  private:
    coroutine_handle<promise_type> coro{};

  public:
    sequence(sequence&) = delete;
    sequence& operator=(sequence&) = delete;
    sequence(sequence&& rhs) noexcept : coro{rhs.coro} {
        rhs.coro = nullptr;
    }
    sequence& operator=(sequence&& rhs) {
        std::swap(coro, rhs.coro);
        return *this;
    }
    sequence() noexcept = default;
    sequence(promise_type* ptr) noexcept
        : coro{coroutine_handle<promise_type>::from_promise(*ptr)} {
    }
    ~sequence() noexcept {
        // delete the coroutine frame
        //  coro.done() won't be checked since the usecase might want it
        //  the library only guarantees there is no leak
        if (coro)
            coro.destroy();
    }

  public:
    iterator begin() noexcept(false) {
        // The first and only moment for this function.
        // `resumeable_handle` must be guaranteed to be non-null
        // by `promise_type`. So we won't follow the scheme of `generator`

        // notice that promise_type used initial suspend
        coro.resume();

        // this line won't be true but will be remained for a while
        if (coro.done())
            return iterator{nullptr};

        // check if it's finished after first resume
        if (coro.promise().current == finished()) //
            return iterator{nullptr};

        return iterator{coro};
    }
    iterator end() noexcept {
        return iterator{nullptr};
    }

  public:
    class promise_type final : public promise_manual_control {
        friend class iterator;
        friend class sequence;

      public:
        pointer current{};
        coroutine_handle<void> task{};

      public:
        auto get_return_object() noexcept -> promise_type* {
            return this;
        }
        void unhandled_exception() noexcept {
            std::terminate();
        }

        // auto final_suspend() const noexcept {
        //     // Delete of `iterator` & `promise`
        //     //
        //     // Unfortunately, it's differ upon scenario that which one should
        //     //   deleted before the other.
        //     // Just suspend here and let them cooperate for it.
        //     //
        //     return suspend_always{};
        // }

        promise_type& yield_value(reference ref) noexcept {
            current = std::addressof(ref);
            // case yield:
            //   iterator will take the value
            return *this;
        }
        template <typename Awaitable>
        Awaitable& yield_value(Awaitable&& a) noexcept {
            current = empty();
            // case empty:
            //    The given awaitable will reactivate this.
            //    NOTICE that iterator is going to suspend after this
            //    AND there is a short gap before the suspend of the iterator
            //
            //    The gap can be critical for multi-threaded scenario
            //
            return a;
        }
        void return_void() noexcept {
            current = finished();
            // case finished:
            //    Activate the iterator anyway.
            //    It's not a good pattern but this point is the appropriate for
            //    the iterator to notice and stop the loop
            this->await_resume();
        }

        bool await_ready() const noexcept {
            // Never suspend if there is a waiting iterator.
            // It will be resumed in `await_resume` function.
            //
            // !!! Using relaxed order here needs more verification !!!
            //
            return task.address() != nullptr;
        }
        void await_suspend(coroutine_handle<void> coro) noexcept {
            // iterator will reactivate this
            task = coro;
        }
        void await_resume() noexcept {
            if (auto _coro = task) {
                task = nullptr; // Resume if and only if
                _coro.resume(); // there is a waiting work
            }
        }
    };

    class iterator final {
      public:
        using iterator_category = std::forward_iterator_tag;

        using difference_type = ptrdiff_t;
        using value_type = T;
        using reference = T const&;
        using pointer = T const*;

      public:
        promise_type* promise{};

      public:
        explicit iterator(std::nullptr_t) noexcept : promise{nullptr} {
        }
        explicit iterator(coroutine_handle<promise_type> coro) noexcept
            : promise{std::addressof(coro.promise())} {
        }

      public:
        iterator& operator++(int) = delete; // post increment
        iterator& operator++() noexcept(false) {
            // reset and advance
            promise->current = empty();
            // iterator resumes promise if it is suspended
            if (auto t = promise->task) {
                promise->task = nullptr;
                t.resume();
            }
            return await_resume();
        }

        bool await_ready() const noexcept {
            // case finished:
            //    Must advance because there is nothing to resume this
            //    iterator
            // case yield:
            //    Continue the loop
            return promise ? promise->current != empty() : true;
        }
        void await_suspend(coroutine_handle<void> coro) noexcept {
            // case empty:
            //   Promise suspended for some reason. Wait for it to yield
            //   Expect promise to resume this iterator appropriately
            promise->task = coro;
        }
        iterator& await_resume() noexcept {
            // case finished:
            //    There is nothing we can do in this iterator.
            //    We have meet the end condition of `for-co_await`
            if (promise &&                      //
                promise->current == finished()) //
                promise = nullptr;              // forget the promise
            return *this;
        }

        pointer operator->() noexcept {
            return promise->current;
        }
        reference operator*() noexcept {
            return *(this->operator->());
        }
        bool operator==(const iterator& rhs) const noexcept {
            return this->promise == rhs.promise;
        }
        bool operator!=(const iterator& rhs) const noexcept {
            return !(*this == rhs);
        }
    };
};

class forget_frame {
  public:
    class promise_type final : public promise_return_destroy {
      public:
        void return_void() noexcept {
            // nothing to do because this is `void` return
        }
        auto get_return_object() noexcept -> forget_frame {
            return {this};
        }
        static auto get_return_object_on_allocation_failure() noexcept
            -> forget_frame {
            return {nullptr};
        }
        // void* operator new(size_t sz) noexcept {
        //     return malloc(sz); // for tracing frame life cycle ...
        // }
        // void operator delete(void* ptr, size_t sz) noexcept {
        //     free(ptr); // for tracing frame life cycle ...
        // }
    };

  private:
    forget_frame(const promise_type*) noexcept {
        // the type truncates all given info about its frame
    }

  public:
    // gcc-10 requires the type to be default constructible
    forget_frame() noexcept = default;
};

class preserve_frame : public coroutine_handle<void> {
  public:
    class promise_type final : public promise_return_preserve {
      public:
        void return_void() noexcept {
            // nothing to do because this is `void` return
        }
        auto get_return_object() noexcept -> preserve_frame {
            return {this};
        }
        static auto get_return_object_on_allocation_failure() noexcept
            -> preserve_frame {
            return {nullptr};
        }
    };

  private:
    preserve_frame(promise_type* p) noexcept : coroutine_handle<void>{} {
        if (p == nullptr)
            return;
        coroutine_handle<void>& ref = *this;
        ref = coroutine_handle<promise_type>::from_promise(*p);
    }

  public:
    // gcc-10 requires the type to be default constructible
    preserve_frame() noexcept = default;
};

class save_frame_t final {
  public:
    // provide interface to receive handle
    // when it's used as an operand of `co_await`
    void await_suspend(coroutine_handle<void> coro) noexcept {
        ref = coro;
    }
    constexpr bool await_ready() noexcept {
        return false;
    }
    constexpr void await_resume() noexcept {
    }

  public:
    explicit save_frame_t(coroutine_handle<void>& target) : ref{target} {
    }

  private:
    coroutine_handle<void>& ref;
};
// use like a generator
auto sequence_yield_once(status_t value = 0) -> sequence<status_t> {
    co_yield value;
    co_return;
};

auto use_sequence_yield_once(status_t& ref) -> forget_frame {
    // clang-format off
    for co_await(auto v : sequence_yield_once(0xBEE))
        ref = v;
    // clang-format on
};
void _require_(bool expr) {
    if (expr)
       return;
    ::exit(EXIT_FAILURE);
}

auto coro_sequence_yield_once_test() {
    status_t storage = -1;
    use_sequence_yield_once(storage);
   _require_(storage == 0xBEE); // storage will receive value

   return EXIT_SUCCESS;
};

int main() {
   return EXIT_SUCCESS;
}
