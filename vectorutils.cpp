#include <iostream>
#include <vector>
#include "vectorutils.h"
using namespace std;

void printvector(std::vector<long> v) {
    long vsize = v.size();
    std::cout << "{";
    for (int i = 0; i < vsize; i++) {
        if (i % 10 == 10) {
            std::cout << "\n ";
        }
        std::cout << v[i];
        if (i < (v.size()) - 1) {
            std::cout << ", ";
        }
    }
    std:cout << "}\n";
}
