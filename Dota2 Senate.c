#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* predictPartyVictory(char* senate) {
    int n = strlen(senate);
    int radiantCount = 0, direCount = 0; // Counters for remaining senators from each party
    int radiantBanned = 0, direBanned = 0; // Flags to indicate if a party's senator is banned
    char* result;

    // Count the number of senators from each party
    for (int i = 0; i < n; ++i) {
        if (senate[i] == 'R') {
            radiantCount++;
        } else if (senate[i] == 'D') {
            direCount++;
        }
    }

    // Simulate the voting process
    while (radiantCount > 0 && direCount > 0) {
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R' && !radiantBanned) {
                if (direCount > 0) {
                    direCount--;
                    direBanned = 1;
                } else {
                    result = "Radiant";
                    radiantCount = 0;
                    break;
                }
            } else if (senate[i] == 'D' && !direBanned) {
                if (radiantCount > 0) {
                    radiantCount--;
                    radiantBanned = 1;
                } else {
                    result = "Dire";
                    direCount = 0;
                    break;
                }
            }
        }
        radiantBanned = 0;
        direBanned = 0;
    }

    // Determine the winner
    if (radiantCount > 0) {
        result = "Radiant";
    } else {
        result = "Dire";
    }

    return result;
}

int main() {
    char senate1[] = "RD";
    printf("Output for senate1: %s\n", predictPartyVictory(senate1));

    char senate2[] = "RDD";
    printf("Output for senate2: %s\n", predictPartyVictory(senate2));

    return 0;
}
