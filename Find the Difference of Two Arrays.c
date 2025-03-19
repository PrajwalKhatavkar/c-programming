#include <stdio.h>
#include <stdlib.h>

struct HashNode {
    int key;
    struct HashNode* next;
};

struct HashSet {
    struct HashNode** buckets;
    int capacity;
};

struct HashSet* createHashSet(int capacity) {
    struct HashSet* set = (struct HashSet*)malloc(sizeof(struct HashSet));
    set->capacity = capacity;
    set->buckets = (struct HashNode**)malloc(capacity * sizeof(struct HashNode*));
    for (int i = 0; i < capacity; ++i) {
        set->buckets[i] = NULL;
    }
    return set;
}

void addToHashSet(struct HashSet* set, int key) {
    int index = abs(key) % set->capacity;
    struct HashNode* node = (struct HashNode*)malloc(sizeof(struct HashNode));
    node->key = key;
    node->next = set->buckets[index];
    set->buckets[index] = node;
}

int containsInHashSet(struct HashSet* set, int key) {
    int index = abs(key) % set->capacity;
    struct HashNode* current = set->buckets[index];
    while (current != NULL) {
        if (current->key == key) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    struct HashSet* set1 = createHashSet(nums1Size);
    struct HashSet* set2 = createHashSet(nums2Size);

    // Add elements of nums1 to set1
    for (int i = 0; i < nums1Size; ++i) {
        addToHashSet(set1, nums1[i]);
    }

    // Add elements of nums2 to set2
    for (int i = 0; i < nums2Size; ++i) {
        addToHashSet(set2, nums2[i]);
    }

    // Find distinct elements in nums1 not present in nums2
    int count1 = 0;
    for (int i = 0; i < nums1Size; ++i) {
        if (!containsInHashSet(set2, nums1[i])) {
            count1++;
        }
    }

    // Find distinct elements in nums2 not present in nums1
    int count2 = 0;
    for (int i = 0; i < nums2Size; ++i) {
        if (!containsInHashSet(set1, nums2[i])) {
            count2++;
        }
    }

    // Allocate memory for the result arrays
    int** result = (int**)malloc(2 * sizeof(int*));
    result[0] = (int*)malloc(count1 * sizeof(int));
    result[1] = (int*)malloc(count2 * sizeof(int));

    // Populate the result arrays
    int index1 = 0;
    for (int i = 0; i < nums1Size; ++i) {
        if (!containsInHashSet(set2, nums1[i])) {
            result[0][index1++] = nums1[i];
        }
    }

    int index2 = 0;
    for (int i = 0; i < nums2Size; ++i) {
        if (!containsInHashSet(set1, nums2[i])) {
            result[1][index2++] = nums2[i];
        }
    }

    // Set return size and column sizes
    *returnSize = 2;
    *returnColumnSizes = (int*)malloc(2 * sizeof(int));
    (*returnColumnSizes)[0] = count1;
    (*returnColumnSizes)[1] = count2;

    return result;
}

void freeHashSet(struct HashSet* set) {
    for (int i = 0; i < set->capacity; ++i) {
        struct HashNode* current = set->buckets[i];
        while (current != NULL) {
            struct HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(set->buckets);
    free(set);
}

int main() {
    int nums1[] = {1, 2, 3};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {2, 4, 6};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);

    int returnSize;
    int* returnColumnSizes;
    int** result = findDifference(nums1, numsSize1, nums2, numsSize2, &returnSize, &returnColumnSizes);

    printf("Output:\n");
    printf("answer[0]: ");
    for (int i = 0; i < returnColumnSizes[0]; ++i) {
        printf("%d ", result[0][i]);
    }
    printf("\n");
    printf("answer[1]: ");
    for (int i = 0; i < returnColumnSizes[1]; ++i) {
        printf("%d ", result[1][
