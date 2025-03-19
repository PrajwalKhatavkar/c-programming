#include <stdio.h>

int minFlips(int a, int b, int c) {
    int flips = 0;
    for (int i = 0; i < 32; i++) { // 32-bit integers
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;
        int bitC = (c >> i) & 1;
        
        if ((bitA | bitB) != bitC) { // Check if (a | b) == c
            if (bitC == 0) {
                flips += (bitA + bitB); // Flips required to make (a | b) == 0
            } else {
                flips += (bitA == 0 && bitB == 0) ? 1 : 2; // Flips required to make (a | b) == 1
            }
        }
    }
    return flips;
}

int main() {
    int a1 = 2, b1 = 6, c1 = 5;
    int a2 = 4, b2 = 2, c2 = 7;
    int a3 = 1, b3 = 2, c3 = 3;

    printf("Output 1: %d\n", minFlips(a1, b1, c1)); // Output: 3
    printf("Output 2: %d\n", minFlips(a2, b2, c2)); // Output: 1
    printf("Output 3: %d\n", minFlips(a3, b3, c3)); // Output: 0

    return 0;
}
