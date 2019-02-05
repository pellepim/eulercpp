#include <iostream>
#include <math.h>
#include <chrono>

using namespace std;

void brute(int n) {
    long sumOfSquares = 0;
    long sum = 0;
    long powOfSum = 0;
    
    for (long i = 0; i <= n; i++) {
        sumOfSquares += pow(i, 2);
        sum += i;
    }

    powOfSum = pow(sum, 2);
    long result = powOfSum - sumOfSquares;
    std::cout << result;
}

void smarter(int n) {
    long powOfSum = pow((n*(n+1))/2, 2);
    long sumOfSquares = (n*(n + 1)*(2*n +1))/6;
    long result = powOfSum - sumOfSquares;
    std::cout << result;
}

int main() {
    auto before_brute = std::chrono::high_resolution_clock::now();
    brute(100);
    auto after_brute = std::chrono::high_resolution_clock::now();
    std::cout << " " << std::chrono::duration_cast<std::chrono::microseconds>(after_brute-before_brute).count()  << "µs" << std::endl;
    smarter(100);
    auto after_smarter = std::chrono::high_resolution_clock::now();
    std::cout << " " << std::chrono::duration_cast<std::chrono::microseconds>(after_smarter-after_brute).count()  << "µs" << std::endl;
}