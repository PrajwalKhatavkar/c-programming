#include <stdio.h>
#include <stdlib.h>

int* countBits(int n, int* returnSize) {
    int* ans = (int*)malloc((n + 1) * sizeof(int));
    *returnSize = n + 1;

    ans[0] = 0;
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i >> 1] + (i & 1);
    }

    return ans;
}

int main() {
    int n = 5;
    int returnSize;
    int* ans = countBits(n, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", ans[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(ans);
    return 0;
}
