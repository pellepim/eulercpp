#include <iostream>
#include "primes.h"
using namespace std;

int main() {
    std::vector<long> primes = prime_factorize(600851475143);
    std::cout << "Largest prime factor: " << primes[primes.size() -1] << "\n";
}
