#!/bin/bash

/opt/llvm/build/bin/clang++ -std=c++2a -stdlib=libc++ -g0 -fcoroutines-ts -I/opt/llvm/build/include/c++/v1 -I/opt/boost-build/include -L/opt/boost-build/lib -lboost_chrono -lpthread timersync1.cpp
