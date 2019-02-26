#ifndef PRIMES
#define PRIMES
#include <vector>

extern std::vector<int> primesUntil200;
extern bool is_prime(long candidate);
extern std::vector<int> primes_to(int n);
extern std::vector<int> sieve(int n);
extern std::vector<long> prime_factorize(long n);

#endif /*PRIMES*/