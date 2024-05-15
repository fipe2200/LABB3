//
// Created by Filip Persson on 2024-05-07.
//
#include "generator/prime/prime_gen.h"
#include "generator/tree/binary_tree.h"
#include "generator/hashtable/hashtable_gen.h"
#include "search_algorithms/binary_search/binary_search.h"
#include "search_algorithms/sequential_search/sequential_search.h"
#include "search_algorithms/binary_tree_search/binary_tree_search.h"
#include "search_algorithms/hash_table_search/hash_table_search.h"
#include "measure/measurements.h"
#include <fstream>
#include <iostream>
#include <chrono>

double performSearches(int method, std::vector<int>& prime_numbers, BinaryTree& binary_tree, HashTable& hash_table) {
    int count = 0;
    int target;
    auto start_time = std::chrono::high_resolution_clock::now();
    do {
        count++;
        target = prime_numbers[rand() % prime_numbers.size()];
        switch (method) {
            case 0:
                if(!binary_search(prime_numbers.begin(), prime_numbers.end(), target)) std::cout << "Error " << target<< std::endl;
                break;
            case 1:
                if(!binary_tree_search(binary_tree, target)) std::cout << "Error " << target<<std::endl;
                break;
            case 2:
                if(!hash_table_search(hash_table, target)) std::cout << "Error "<< target<<std::endl;
                break;
            case 3:
                if(!sequential_search(prime_numbers, target)) std::cout << "Error " << target<<std::endl;
                break;
            default:
                break;
        }
    } while (std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - start_time).count() < 0.1);
    auto end = std::chrono::high_resolution_clock::now();
    auto result = std::chrono::duration_cast<std::chrono::duration<double>>(end - start_time).count();
    return result / count;
}

const int SIZE = 2000;
const int REPETITIONS = 10;
const int SAMPLES = 50;

int main(){
    srand(time(NULL));
    std::ofstream outfile;
    std::chrono::high_resolution_clock::time_point start, end;
    start = std::chrono::high_resolution_clock::now();
    for(int method = 0; method < 4; method++){
        std::string filename;
        switch (method) {
            case 0:
                filename = "binary_search";
                break;
            case 1:
                filename = "binary_tree_search";
                break;
            case 2:
                filename = "hash_table_search";
                break;
            case 3:
                filename = "sequential_search";
                break;
            default:
                break;
        }
        outfile.open("/Users/filippersson/Desktop/DOA/Labbar/LABB3/plot/"+filename + ".txt");

        for (int rep = 0; rep < REPETITIONS; ++rep) {

            int size = SIZE * (rep+1);

            //filling the data structures
            std::vector<int> prime_numbers = SieveOfEratosthenes(size);
            BinaryTree binary_tree(prime_numbers);
            HashTable hash_table(size);
            for (auto& i: prime_numbers){
                hash_table.insert(i);
            }

            //performing searches
            std::vector<double> timings;
            for (int i = 0; i < SAMPLES; ++i) {
                auto time = performSearches(method, prime_numbers, binary_tree, hash_table);
                timings.push_back(time);
            }

            double meanTime = avg(timings);
            double stdevTime = standardAv(timings);

            outfile << size << " " << meanTime << " " << stdevTime << std::endl;
        }
        outfile.close();
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Total run time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count() << std::endl;
    return 0;
}
