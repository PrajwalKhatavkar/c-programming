#include <stdio.h>
#include <stdlib.h>

// Structure for the priority queue (min heap)
typedef struct {
    int* heap;
    int size;
} PriorityQueue;

// Function to initialize the priority queue
PriorityQueue* initPriorityQueue(int maxSize) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->heap = (int*)malloc((maxSize + 1) * sizeof(int));
    pq->size = 0;
    return pq;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min heap property
void heapify(PriorityQueue* pq, int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= pq->size && pq->heap[left] < pq->heap[smallest]) {
        smallest = left;
    }
    if (right <= pq->size && pq->heap[right] < pq->heap[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(&pq->heap[i], &pq->heap[smallest]);
        heapify(pq, smallest);
    }
}

// Function to insert an element into the priority queue
void insert(PriorityQueue* pq, int val) {
    pq->heap[++pq->size] = val;
    int i = pq->size;
    while (i > 1 && pq->heap[i] < pq->heap[i / 2]) {
        swap(&pq->heap[i], &pq->heap[i / 2]);
        i /= 2;
    }
}

// Function to remove and return the smallest element from the priority queue
int popSmallest(PriorityQueue* pq) {
    if (pq->size == 0) {
        return -1; // No elements in the priority queue
    }
    int smallest = pq->heap[1];
    pq->heap[1] = pq->heap[pq->size--];
    heapify(pq, 1);
    return smallest;
}

// SmallestInfiniteSet class
typedef struct {
    PriorityQueue* pq;
    int maxSize;
} SmallestInfiniteSet;

// Function to initialize the SmallestInfiniteSet object
SmallestInfiniteSet* SmallestInfiniteSetCreate() {
    SmallestInfiniteSet* set = (SmallestInfiniteSet*)malloc(sizeof(SmallestInfiniteSet));
    set->maxSize = 1000;
    set->pq = initPriorityQueue(set->maxSize);
    return set;
}

// Function to remove and return the smallest integer from the set
int popSmallest(SmallestInfiniteSet* obj) {
    return popSmallest(obj->pq);
}

// Function to add a positive integer back into the set
void addBack(SmallestInfiniteSet* obj, int num) {
    insert(obj->pq, num);
}

// Sample test cases
int main() {
    SmallestInfiniteSet* smallestInfiniteSet = SmallestInfiniteSetCreate();
    addBack(smallestInfiniteSet, 2);
    printf("%d\n", popSmallest(smallestInfiniteSet)); // Output: 1
    printf("%d\n", popSmallest(smallestInfiniteSet)); // Output: 2
    printf("%d\n", popSmallest(smallestInfiniteSet)); // Output: 3
    addBack(smallestInfiniteSet, 1);
    printf("%d\n", popSmallest(smallestInfiniteSet)); // Output: 1
    printf("%d\n", popSmallest(smallestInfiniteSet)); // Output: 4
    printf("%d\n", popSmallest(smallestInfiniteSet)); // Output: 5

    return 0;
}
