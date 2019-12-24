#!/bin/bash
#g++ -std=c++2a -I/opt/gcc-latest -L/opt/gcc-latest ./cpp_v20_ex_p518.cpp -o cpp_v20_ex_p518
#clang -cc1 -fdump-record-layouts ./cpp_v11_ex_dump_mem_layout.cpp | tee dump.txt
#clang++ -std=c++11 cpp_v11_ex_auto_ptr_deref.cpp -o cpp_v11_ex_auto_ptr_deref
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_mpl_intro.cpp -o cpp_v11_mpl_intro
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_mpl_integr_wrappers.cpp -o cpp_v11_mpl_integr_wrappers
clang++ -std=c++11 -I/opt/boost-build/include -L/opt/boost-build/lib cpp_v11_mpl_plus.cpp -o cpp_v11_mpl_plus
