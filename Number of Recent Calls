#include <stdlib.h>

typedef struct {
    int *queue; // Queue to store timestamps
    int front; // Index of the front element
    int rear; // Index of the rear element
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->queue = (int*)malloc(10000 * sizeof(int)); // Assuming at most 10^4 calls to ping
    obj->front = 0;
    obj->rear = -1;
    return obj;
}

int ping(RecentCounter* obj, int t) {
    // Remove timestamps older than 3000 milliseconds
    while (obj->front <= obj->rear && obj->queue[obj->front] < t - 3000) {
        obj->front++;
    }
    // Push the current timestamp onto the queue
    obj->queue[++obj->rear] = t;
    // Return the number of requests in the past 3000 milliseconds
    return obj->rear - obj->front + 1;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->queue);
    free(obj);
}
int main() {
    RecentCounter* obj = recentCounterCreate();
    printf("%d\n", ping(obj, 1));     // Output: 1
    printf("%d\n", ping(obj, 100));   // Output: 2
    printf("%d\n", ping(obj, 3001));  // Output: 3
    printf("%d\n", ping(obj, 3002));  // Output: 3
    recentCounterFree(obj);
    return 0;
}
