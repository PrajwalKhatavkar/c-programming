#include <stdio.h>
#include <stdlib.h>

// Structure to represent a worker
typedef struct {
    int cost;
    int index;
} Worker;

// Function to compare two workers based on their costs (used for priority queue)
int compare(const void* a, const void* b) {
    Worker* worker1 = (Worker*)a;
    Worker* worker2 = (Worker*)b;
    if (worker1->cost == worker2->cost) {
        return worker1->index - worker2->index; // Break tie by smallest index
    }
    return worker1->cost - worker2->cost;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int minCostToHireWorkers(int* costs, int costsSize, int k, int candidates) {
    Worker* workers = (Worker*)malloc(candidates * sizeof(Worker));
    for (int i = 0; i < candidates; i++) {
        workers[i].cost = costs[i];
        workers[i].index = i;
    }
    // Sort the workers based on their costs
    qsort(workers, candidates, sizeof(Worker), compare);

    int total_cost = 0;
    int session = 0;
    while (session < k) {
        Worker worker = workers[0]; // Get the worker with the lowest cost
        total_cost += worker.cost;
        session++;
        if (session == k) break;
        int remaining = candidates - 1;
        for (int i = 0; i < remaining; i++) {
            workers[i] = workers[i + 1]; // Shift remaining workers to the left
        }
        // Add the next candidate worker to the priority queue
        workers[remaining].cost = costs[candidates + session - 1];
        workers[remaining].index = candidates + session - 1;
        // Restore the heap property after adding the new worker
        qsort(workers, candidates, sizeof(Worker), compare);
    }
    free(workers);
    return total_cost;
}

int main() {
    int costs1[] = {17, 12, 10, 2, 7, 2, 11, 20, 8};
    int k1 = 3, candidates1 = 4;
    int costsSize1 = sizeof(costs1) / sizeof(costs1[0]);
    int result1 = minCostToHireWorkers(costs1, costsSize1, k1, candidates1);
    printf("%d\n", result1); // Output: 11

    int costs2[] = {1, 2, 4, 1};
    int k2 = 3, candidates2 = 3;
    int costsSize2 = sizeof(costs2) / sizeof(costs2[0]);
    int result2 = minCostToHireWorkers(costs2, costsSize2, k2, candidates2);
    printf("%d\n", result2); // Output: 4

    return 0;
}
