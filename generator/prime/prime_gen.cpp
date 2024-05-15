//
// Created by Filip Persson on 2024-05-07.
//

#include "prime_gen.h"

std::vector<int> SieveOfEratosthenes(int n){
    bool prime[n + 1];
    std::memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    std::vector<int> primes;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
    return primes;
}