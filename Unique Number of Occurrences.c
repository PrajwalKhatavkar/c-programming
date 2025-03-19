#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct HashNode {
    int key;
    int count;
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
    struct HashNode* current = set->buckets[index];
    while (current != NULL) {
        if (current->key == key) {
            current->count++;
            return;
        }
        current = current->next;
    }
    struct HashNode* node = (struct HashNode*)malloc(sizeof(struct HashNode));
    node->key = key;
    node->count = 1;
    node->next = set->buckets[index];
    set->buckets[index] = node;
}

bool isUniqueOccurrences(int* arr, int arrSize) {
    struct HashSet* countSet = createHashSet(arrSize);
    struct HashSet* occurrenceSet = createHashSet(arrSize);

    // Count occurrences of each element
    for (int i = 0; i < arrSize; ++i) {
        addToHashSet(countSet, arr[i]);
    }

    // Check if the counts are unique
    for (int i = 0; i < countSet->capacity; ++i) {
        struct HashNode* current = countSet->buckets[i];
        while (current != NULL) {
            if (addToHashSet(occurrenceSet, current->count) == false) {
                return false;
            }
            current = current->next;
        }
    }

    return true;
}

int main() {
    int arr1[] = {1, 2, 2, 1, 1, 3};
    int arrSize1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Output for arr1: %s\n", isUniqueOccurrences(arr1, arrSize1) ? "true" : "false");

    int arr2[] = {1, 2};
    int arrSize2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Output for arr2: %s\n", isUniqueOccurrences(arr2, arrSize2) ? "true" : "false");

    int arr3[] = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    int arrSize3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Output for arr3: %s\n", isUniqueOccurrences(arr3, arrSize3) ? "true" : "false");

    return 0;
}
