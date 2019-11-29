#!/bin/bash
clang++ -std=c++2a ./cpp_v20_ex_p90.cpp -o cpp_v20_ex_p90
clang++ -std=c++2a ./cpp_v20_ex_p126.cpp -o cpp_v20_ex_p126
g++ -std=c++2a -I/opt/gcc-latest -L/opt/gcc-latest ./cpp_v20_ex_p518.cpp -o cpp_v20_ex_p518
g++ -std=c++2a -I/opt/gcc-latest -L/opt/gcc-latest ./cpp_v17_ex_hash.cpp -o cpp_v17_ex_hash
g++ -std=c++2a -I/opt/gcc-latest -L/opt/gcc-latest ./cpp_v20_ex_hashable.cpp -o cpp_v20_ex_hashable
clang++ -std=c++11 -DDEBUG ./cpp_v11_ex_variadic_adder.cpp -o cpp_v11_ex_variadic_adder
clang++ -std=c++11 -DDEBUG ./cpp_v11_ex_variadic_pair_comp.cpp -o cpp_v11_ex_variadic_pair_comp
