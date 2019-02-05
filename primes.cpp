#include <iostream>
#include <math.h>
#include <vector>
#include "primes.h"
using namespace std;

 std::vector<int> primesUntil200 {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151,
    157, 163, 167, 173, 179, 181, 191, 193, 197, 199
};

/**
 * Algorithm for determining whether an integer candidate is a prime number
 */
bool is_prime(long candidate) {
    long maxPotentialDivisor;
    long currentDivisor;

    // If the candidate is 3 or lower, it is a prime if it is larger than 1
    if (candidate <= 3) {
        return candidate > 1;
    }

    // If the candidate is even or divisible by 3 - it cannot be a prime
    if (candidate % 2 == 0 || candidate % 3 == 0) {
        return false;
    }

    // it sqrt(candidate) is bigger than 200, we check if it is divisible by
    // any of the primes until 200, if so - it cannot be a prime.
    if (sqrt(candidate) > 200) {
        for (int i = 0; i < primesUntil200.size(); i++) {
            if (candidate % primesUntil200[i] == 0) {
                return false;
            }
        }
    }

    // Otherwise, we painstakingly iterate over potential divisors from 5 to
    // sqrt(candidate). For each iteration we check whether the candidate is
    // evenly divisible by the current divisor, or by the currentDivisor + 2 -
    // if so, it cannot be a prime. Then we skip ahead six potential divisors,
    // bypassing even divisibility by 3 and 5 (which we've already discarded)
    currentDivisor = 5;
    maxPotentialDivisor = sqrt(candidate);
    for (;currentDivisor <= maxPotentialDivisor; currentDivisor+=6) {
        if (candidate % currentDivisor == 0 || candidate % (currentDivisor + 2) == 0) {
            return false;
        }
    }

    // Seems like you got a prime, matey!
    return true;
}

std::vector<long> prime_factorize(long n) {
    std::vector<long> prime_factors {};
    
    // While n is evenly divisible by 2, 2 is a prime factor of n
    while (n % 2 == 0) {
        prime_factors.push_back(2);
        n = n / 2;
    }

    // While n is evenly divisible by 3, 3 is a prime factor of n
    while (n % 3 == 0) {
        prime_factors.push_back(3);
        n = n / 3;
    }

    for (long i = 5; i <= sqrt(n); i+=2) {
        if (n % i == 0) {
            prime_factors.push_back(i);
            n = n / i;
        }
    }

    if (n > 2) {
        prime_factors.push_back(n);
    }

    return prime_factors;
}
