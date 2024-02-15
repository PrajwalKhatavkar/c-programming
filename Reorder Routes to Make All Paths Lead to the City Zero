#include <stdbool.h>
#include <stdlib.h>

void dfs(int** graph, int* visited, int city) {
    visited[city] = 1;
    for (int i = 0; graph[city][i] != -1; ++i) {
        int neighbor = graph[city][i];
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    // Initialize adjacency list graph
    int** graph = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i) {
        graph[i] = (int*)malloc(sizeof(int) * (n + 1)); // +1 for sentinel value -1
        for (int j = 0; j <= n; ++j) {
            graph[i][j] = -1; // Initialize all to -1
        }
    }
    for (int i = 0; i < connectionsSize; ++i) {
        int a = connections[i][0];
        int b = connections[i][1];
        graph[a][0]++;
        graph[a][graph[a][0]] = b;
        graph[b][0]++;
        graph[b][graph[b][0]] = a;
    }
    
    // Perform DFS to determine road orientations
    int* visited = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        visited[i] = 0;
    }
    int count = 0;
    dfs(graph, visited, 0);
    for (int i = 0; i < connectionsSize; ++i) {
        int a = connections[i][0];
        int b = connections[i][1];
        if (!visited[a] && visited[b]) {
            count++;
        }
    }
    
    // Clean up memory
    for (int i = 0; i < n; ++i) {
        free(graph[i]);
    }
    free(graph);
    free(visited);
    
    return count;
}

int main() {
    int connections1[][2] = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    int* connectionsPtr1[] = {connections1[0], connections1[1], connections1[2], connections1[3], connections1[4]};
    int n1 = 6;
    printf("Example 1 output: %d\n", minReorder(n1, connectionsPtr1, 5, NULL));
    
    int connections2[][2] = {{1,0},{1,2},{3,2},{3,4}};
    int* connectionsPtr2[] = {connections2[0], connections2[1], connections2[2], connections2[3]};
    int n2 = 5;
    printf("Example 2 output: %d\n", minReorder(n2, connectionsPtr2, 4, NULL));
    
    int connections3[][2] = {{1,0},{2,0}};
    int* connectionsPtr3[] = {connections3[0], connections3[1]};
    int n3 = 3;
    printf("Example 3 output: %d\n", minReorder(n3, connectionsPtr3, 2, NULL));
    
    return 0;
}
