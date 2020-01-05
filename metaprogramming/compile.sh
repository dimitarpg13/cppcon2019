#!/bin/bash
#g++ -std=c++2a -I/opt/gcc-latest -L/opt/gcc-latest ./cpp_v20_ex_p518.cpp -o cpp_v20_ex_p518
#clang -cc1 -fdump-record-layouts ./cpp_v11_ex_dump_mem_layout.cpp | tee dump.txt
#clang++ -std=c++11 cpp_v11_ex_auto_ptr_deref.cpp -o cpp_v11_ex_auto_ptr_deref
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_mpl_intro.cpp -o cpp_v11_mpl_intro
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_mpl_integr_wrappers.cpp -o cpp_v11_mpl_integr_wrappers
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_mpl_plus.cpp -o cpp_v11_mpl_plus
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_mpl_quantity_algebra.cpp -o cpp_v11_mpl_quantity_algebra
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_mpl_quantity_algebra_mult_problem.cpp -o cpp_v11_mpl_quantity_algebra_mult_problem > compile_error.txt 2>&1
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_mpl_quantity_algebra_another_mult_problem.cpp -o cpp_v11_mpl_quantity_algebra_another_mult_problem
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_mpl_quantity_algebra_problems_fixed.cpp -o cpp_v11_mpl_quantity_algebra_problems_fixed > compile_error2.txt 2>&1 
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_mpl_quantity_algebra_final.cpp -o cpp_v11_mpl_quantity_algebra_final
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_mpl_quantity_algebra_final2.cpp -o cpp_v11_mpl_quantity_algebra_final2
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_mpl_quantity_algebra_final3.cpp -o cpp_v11_mpl_quantity_algebra_final3
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_higher_order_metafunc1.cpp -o cpp_v11_higher_order_metafunc1
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_higher_order_metafunc2.cpp -o cpp_v11_higher_order_metafunc2 > compile_error3.txt 2>&1
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_higher_order_metafunc3.cpp -o cpp_v11_higher_order_metafunc3
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_variadic_templ1.cpp -o cpp_v11_variadic_templ1
clang++ -std=c++14 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_naive_placeholder_impl.cpp -o cpp_v11_naive_placeholder_impl
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_trivial_vector_gen.cpp -o cpp_v11_trivial_vector_gen
