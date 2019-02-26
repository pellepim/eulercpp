#include <iostream>
#include "primes.h"
#include "vectorutils.h"

using namespace std;

bool test_is_prime() {
    for (int i = 0; i < primesUntil200.size(); i++) {
        if (!is_prime(primesUntil200[i])) {
            std::cout << "TEST: is_prime failed: " << primesUntil200[i] << " should be a prime.\n";
            return false;
        }
    }

    return true;
}

bool test_prime_factorize() {
    std::vector<long> actual = prime_factorize(315);
    std::vector<long> expected = {3, 3, 5, 7};

    if (actual != expected) {
        std::cout << "TEST: prime_factorize failed\n";
        for (int i = 0; i < actual.size(); i++) {
            std::cout << actual[i] << " ";
        }
        std::cout << "\n";
        return false;
    }

    return true;
}

bool test_primes_up_to() {
    std::vector<int> primes = primes_to(400);
    printvector(primes);  
}

int main() {
    if (test_is_prime() &&
        test_prime_factorize() &&
        test_primes_up_to()) {
        std::cout << "All tests are green\n";
        return 0;
    }
    
    std::cout << "Something is amiss\n";
    return 1;
}
