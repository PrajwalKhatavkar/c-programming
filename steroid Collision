#include <stdio.h>
#include <stdlib.h>

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = (int*)malloc(asteroidsSize * sizeof(int));
    int top = -1; // Index of the top element in the stack

    for (int i = 0; i < asteroidsSize; ++i) {
        int curr = asteroids[i];

        if (curr > 0) {
            // Asteroid moving to the right, push onto stack
            stack[++top] = curr;
        } else {
            // Asteroid moving to the left, handle collisions
            while (top >= 0 && stack[top] > 0 && stack[top] < -curr) {
                // Pop asteroids moving to the right until collision or empty stack
                top--;
            }

            if (top >= 0 && stack[top] > 0 && stack[top] == -curr) {
                // Asteroids collide and explode
                top--;
            } else if (top < 0 || stack[top] < 0) {
                // No collision or no asteroids moving to the right, push onto stack
                stack[++top] = curr;
            }
        }
    }

    *returnSize = top + 1;
    return stack;
}

int main() {
    int asteroids1[] = {5, 10, -5};
    int size1;
    int* result1 = asteroidCollision(asteroids1, 3, &size1);
    printf("Output for asteroids1: ");
    for (int i = 0; i < size1; ++i) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    free(result1);

    int asteroids2[] = {8, -8};
    int size2;
    int* result2 = asteroidCollision(asteroids2, 2, &size2);
    printf("Output for asteroids2: ");
    for (int i = 0; i < size2; ++i) {
        printf("%d ", result2[i]);
    }
    printf("\n");
    free(result2);

    int asteroids3[] = {10, 2, -5};
    int size3;
    int* result3 = asteroidCollision(asteroids3, 3, &size3);
    printf("Output for asteroids3: ");
    for (int i = 0; i < size3; ++i) {
        printf("%d ", result3[i]);
    }
    printf("\n");
    free(result3);

    return 0;
}
