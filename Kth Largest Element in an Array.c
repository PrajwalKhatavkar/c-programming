#include <stdio.h>
#include <stdlib.h>

// Min heap data structure
typedef struct {
    int* heap;
    int size;
} MinHeap;

// Function to initialize the min heap
MinHeap* initMinHeap(int k) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->heap = (int*)malloc(k * sizeof(int));
    minHeap->size = 0;
    return minHeap;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min heap property
void heapify(MinHeap* minHeap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < minHeap->size && minHeap->heap[left] < minHeap->heap[smallest]) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->heap[right] < minHeap->heap[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(&minHeap->heap[i], &minHeap->heap[smallest]);
        heapify(minHeap, smallest);
    }
}

// Function to insert an element into the min heap
void insert(MinHeap* minHeap, int val) {
    if (minHeap->size == 0) {
        minHeap->heap[0] = val;
        minHeap->size++;
        return;
    }
    if (minHeap->size < k) {
        minHeap->heap[minHeap->size++] = val;
        int i = minHeap->size - 1;
        while (i > 0 && minHeap->heap[(i - 1) / 2] > minHeap->heap[i]) {
            swap(&minHeap->heap[(i - 1) / 2], &minHeap->heap[i]);
            i = (i - 1) / 2;
        }
    } else if (val > minHeap->heap[0]) {
        minHeap->heap[0] = val;
        heapify(minHeap, 0);
    }
}

// Function to find the kth largest element
int findKthLargest(int* nums, int numsSize, int k) {
    MinHeap* minHeap = initMinHeap(k);

    for (int i = 0; i < numsSize; ++i) {
        insert(minHeap, nums[i]);
    }

    return minHeap->heap[0];
}

// Sample test cases
int main() {
    int nums1[] = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Output for Test Case 1: %d\n", findKthLargest(nums1, numsSize1, k1));

    int nums2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Output for Test Case 2: %d\n", findKthLargest(nums2, numsSize2, k2));

    return 0;
}
