#include <iostream>
#include "primes.h"
#include <vector>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n = 10000000;
    if (argc > 1) {
        n = strtol(argv[1], nullptr, 0);
    }
    std::vector<int> primes = sieve(n);
    std::cout << primes.size() << endl;
}