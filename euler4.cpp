#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include "primes.h"
using namespace std;

bool ispalindrome(int maxNumber) {
    std::string s1 = std::to_string(maxNumber);
    std::string s2 = s1;

    std::reverse(s2.begin(), s2.end());;
    return s1 == s2;
}


int main() {
    int currentMax = 0;
    for (int i = 999; i >= 100; i--) {
        for (int j = 999; j >= 100; j--) {
            if (ispalindrome(i*j)) {
                if (i*j > currentMax) {
                    cout << i << " * " << j << " = " << i*j << "\n";
                    currentMax = i*j;
                }
            }
        }
    }

    cout << "Final result\n";
}
