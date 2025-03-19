#include <stdio.h>

int largestAltitude(int* gain, int gainSize) {
    int current_altitude = 0;
    int max_altitude = 0;

    for (int i = 0; i < gainSize; ++i) {
        current_altitude += gain[i];
        if (current_altitude > max_altitude) {
            max_altitude = current_altitude;
        }
    }

    return max_altitude;
}

int main() {
    int gain1[] = {-5, 1, 5, 0, -7};
    int gainSize1 = sizeof(gain1) / sizeof(gain1[0]);
    printf("Output for gain1: %d\n", largestAltitude(gain1, gainSize1));

    int gain2[] = {-4, -3, -2, -1, 4, 3, 2};
    int gainSize2 = sizeof(gain2) / sizeof(gain2[0]);
    printf("Output for gain2: %d\n", largestAltitude(gain2, gainSize2));

    return 0;
}
