#include <iostream>
using namespace std;

bool isEven(int fib) {
    return fib % 2 == 0;
}

int sumFromStepping() {
    int fib[2] {1, 2};
    int sum = 0;
    int nextFib;

    while (fib[1] < 4000000) {
        if (isEven(fib[0])) {
            sum += fib[0];
        } else if (isEven(fib[1])) {
            sum += fib[1];
        }

        nextFib = fib[0] + fib[1];

        fib[0] = nextFib;
        fib[1] = nextFib + fib[1];
    }

    return sum;
}

int sumFromEveryThird() {
    int a, b = 1;
    int c = 2;
    int sum = 0;
    while (c < 4000000) {
        sum += c;
        a = b + c;
        b = c + a;
        c = a + b;
    }

    return sum;
}

int main() {
    printf("Sum from stepping: %d\n", sumFromStepping());
    printf("Sum from every third: %d\n", sumFromEveryThird());

}