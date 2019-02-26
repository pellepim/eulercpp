#include <iostream>
#include <queue>

using namespace std;

int main() {
    std::queue<int> queue13; 
    long maxValue = 0;

    const char *digits = "73167176531330624919225119674426574742355349194934"
                         "96983520312774506326239578318016984801869478851843"
                         "85861560789112949495459501737958331952853208805511"
                         "12540698747158523863050715693290963295227443043557"
                         "66896648950445244523161731856403098711121722383113"
                         "62229893423380308135336276614282806444486645238749"
                         "30358907296290491560440772390713810515859307960866"
                         "70172427121883998797908792274921901699720888093776"
                         "65727333001053367881220235421809751254540594752243"
                         "52584907711670556013604839586446706324415722155397"
                         "53697817977846174064955149290862569321978468622482"
                         "83972241375657056057490261407972968652414535100474"
                         "82166370484403199890008895243450658541227588666881"
                         "16427171479924442928230863465674813919123162824586"
                         "17866458359124566529476545682848912883142607690042"
                         "24219022671055626321111109370544217506941658960408"
                         "07198403850962455444362981230987879927244284909188"
                         "84580156166097919133875499200524063689912560717606"
                         "05886116467109405077541002256983155200055935729725"
                         "71636269561882670428252483600823257530420752963450";
    
    
    // Iterate through each digit
    for (int i = 0; digits[i] != '\0'; i++) {
        int digit = digits[i] - '0'; // convert to int
        
        // If the digit is zero, there's no need to add it to the queue
        // Instead we empty the queue and skip forward
        if (digit == 0 && !queue13.empty()) {
            std::queue<int> emptyQueue;
            std::swap(queue13, emptyQueue);
            i += 1;
            continue;
        }
        
        // If the digit is non-zero, we add it to the queue
        queue13.push(digit);

        // If the queue is larger than 13 - we pop the front
        if (queue13.size() > 13) {
            queue13.pop();
        }

        // If the queue is exactly 13, then we calculate the product
        // of the digits in the queue. If the product is larger than
        // previous maxValue, we replace it.
        std::queue<int> tmpQueue = queue13;
        long currentProduct = 1;
        
        while(!tmpQueue.empty()) {
            currentProduct *= tmpQueue.front();
            tmpQueue.pop();
        }

        if (currentProduct > maxValue) {
            maxValue = currentProduct;
        }
    }
    std::cout << maxValue << std::endl;
}