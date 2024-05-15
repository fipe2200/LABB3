cmake_minimum_required(VERSION 3.27)
project(LABB3)

set(CMAKE_CXX_STANDARD 14)

add_executable(LABB3
        main.cpp
        generator/prime/prime_gen.h
        generator/prime/prime_gen.cpp
        generator/tree/binary_tree.h
        generator/hashtable/hashtable_gen.h
        generator/hashtable/hashtable_gen.cpp
        generator/tree/binary_tree.cpp
        measure/measurements.h
        measure/measurements.h
        measure/measurements.cpp
        measure/measurements.h
        search_algorithms/binary_search/binary_search.h
        search_algorithms/binary_tree_search/binary_tree_search.h
        search_algorithms/hash_table_search/hash_table_search.h
        search_algorithms/sequential_search/sequential_search.h
        search_algorithms/binary_search/binary_search.cpp
        search_algorithms/hash_table_search/hash_table_search.cpp
        search_algorithms/binary_tree_search/binary_tree_search.cpp
        search_algorithms/sequential_search/sequential_search.cpp)
