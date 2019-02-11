#include <iostream>
#include "primes.h"

using namespace std;

int main() {
    int foundPrimes = 0;
    long i = 0;
    while (foundPrimes <= 10001) {
        if (i < 3) {
            i++;
        } else {
            i+=2;
        }
        if (is_prime(i)) {
            foundPrimes++;
        }
    }
    std::cout << i << endl;
}