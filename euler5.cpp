#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <chrono>
#include "primes.h"
#include "vectorutils.h"

using namespace std;

int brute() {
    long smallest = 20*19;

    while (true) {
        bool hit = true;
        for (int i = 10; i <= 20; i++) {
            if (smallest % i != 0) {
                hit = false;
                break;
            }
        }
        if (hit) {
            return smallest;         
        }
        smallest++;
    }
}

int smarter() {
    std::map<long, int> factor_exponent_count;
    long result = 1;
    for (int i = 2; i <= 20; i++) {
        std::map<long, int> temp_exponent_count;
        std::vector<long> factors = prime_factorize(i);
        for (int j = 0; j < factors.size(); j++) {
            temp_exponent_count[factors[j]]++;
            int current_val = temp_exponent_count[factors[j]];
        }
        
        for (auto const& x  : temp_exponent_count) {
           long factor = x.first;
           int exponent = x.second;

           if (exponent > factor_exponent_count[factor]) {
               factor_exponent_count[factor] = exponent;
           }
        }
    }

    for (auto const& x  : factor_exponent_count) {
        long factor = x.first;
        int exponent = x.second;

        result *= pow(factor, exponent);
    }


    return result;
}

int main() {
    auto before_brute = std::chrono::high_resolution_clock::now();
    cout << brute();
    auto after_brute = std::chrono::high_resolution_clock::now();
    cout << " " << std::chrono::duration_cast<std::chrono::milliseconds>(after_brute-before_brute).count()  << "ms" << std::endl;
    cout << smarter();
    auto after_smarter = std::chrono::high_resolution_clock::now();
    cout << " " << std::chrono::duration_cast<std::chrono::microseconds>(after_smarter-after_brute).count()  << "ms" << std::endl;
}