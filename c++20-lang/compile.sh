#!/bin/bash
clang++ -std=c++2a ./cpp_v20_ex_p90.cpp -o cpp_v20_ex_p90
clang++ -std=c++2a ./cpp_v20_ex_p126.cpp -o cpp_v20_ex_p126
g++ -std=c++2a -I/opt/gcc-latest -L/opt/gcc-latest ./cpp_v20_ex_p518.cpp -o cpp_v20_ex_p518
g++ -std=c++2a -I/opt/gcc-latest -L/opt/gcc-latest ./cpp_v17_ex_hash.cpp -o cpp_v17_ex_hash
g++ -std=c++2a -I/opt/gcc-latest -L/opt/gcc-latest ./cpp_v20_ex_hashable.cpp -o cpp_v20_ex_hashable
clang++ -std=c++11 -DDEBUG ./cpp_v11_ex_variadic_adder.cpp -o cpp_v11_ex_variadic_adder
clang++ -std=c++11 -DDEBUG ./cpp_v11_ex_variadic_pair_comp.cpp -o cpp_v11_ex_variadic_pair_comp
clang -cc1 -fdump-record-layouts ./cpp_v11_ex_dump_mem_layout.cpp | tee dump.txt
clang -cc1 -fdump-record-layouts ./cpp_v11_ex1_semantics_of_data.cpp | tee dump1.txt
clang++ -std=c++11 ./cpp_v11_ex2_semantics_of_data.cpp -o cpp_v11_ex2_semantics_of_data
g++ -std=c++2a -I/opt/gcc-latest -L/opt/gcc-latest ./cpp_v20_ex_launder.cpp -o cpp_v20_ex_launder
