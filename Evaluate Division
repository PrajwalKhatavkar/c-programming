#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARIABLES 20

// Graph Node Structure
typedef struct Node {
    char name[6]; // Variable name
    struct Edge* edges[MAX_VARIABLES]; // Edges to other nodes
    int numEdges; // Number of edges
} Node;

// Edge Structure
typedef struct Edge {
    struct Node* destination; // Destination node
    double weight; // Edge weight
} Edge;

// Function to perform DFS and find the path from start to end variable
double dfs(Node* start, Node* end, double value, int* visited) {
    // Mark the current node as visited
    visited[start - nodes] = 1;

    // If we reach the end variable, return the value
    if (start == end) return value;

    // Iterate over the edges of the current node
    for (int i = 0; i < start->numEdges; ++i) {
        Edge* edge = start->edges[i];
        Node* next = edge->destination;
        double newValue = value * edge->weight;
        
        // If the next node is not visited, recursively call DFS
        if (!visited[next - nodes]) {
            double result = dfs(next, end, newValue, visited);
            // If a path is found, return the result
            if (result != -1.0) return result;
        }
    }
    // If no path is found, return -1.0
    return -1.0;
}

// Function to find the index of a variable in the nodes array
int findVariableIndex(char* name, Node* nodes, int numNodes) {
    for (int i = 0; i < numNodes; ++i) {
        if (strcmp(nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

double* calcEquation(char *** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char *** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Initialize return array
    double* result = (double*)malloc(sizeof(double) * queriesSize);
    *returnSize = queriesSize;

    // Create graph nodes array
    Node* nodes = (Node*)malloc(sizeof(Node) * MAX_VARIABLES);
    int numNodes = 0;

    // Construct the graph
    for (int i = 0; i < equationsSize; ++i) {
        char* src = equations[i][0];
        char* dest = equations[i][1];
        double weight = values[i];
        
        // Find or add source node
        int srcIndex = findVariableIndex(src, nodes, numNodes);
        if (srcIndex == -1) {
            srcIndex = numNodes++;
            strcpy(nodes[srcIndex].name, src);
            nodes[srcIndex].numEdges = 0;
        }

        // Find or add destination node
        int destIndex = findVariableIndex(dest, nodes, numNodes);
        if (destIndex == -1) {
            destIndex = numNodes++;
            strcpy(nodes[destIndex].name, dest);
            nodes[destIndex].numEdges = 0;
        }

        // Add edge from source to destination
        nodes[srcIndex].edges[nodes[srcIndex].numEdges] = (Edge*)malloc(sizeof(Edge));
        nodes[srcIndex].edges[nodes[srcIndex].numEdges]->destination = &nodes[destIndex];
        nodes[srcIndex].edges[nodes[srcIndex].numEdges]->weight = weight;
        nodes[srcIndex].numEdges++;

        // Add edge from destination to source
        nodes[destIndex].edges[nodes[destIndex].numEdges] = (Edge*)malloc(sizeof(Edge));
        nodes[destIndex].edges[nodes[destIndex].numEdges]->destination = &nodes[srcIndex];
        nodes[destIndex].edges[nodes[destIndex].numEdges]->weight = 1.0 / weight;
        nodes[destIndex].numEdges++;
    }

    // Process queries
    for (int i = 0; i < queriesSize; ++i) {
        char* src = queries[i][0];
        char* dest = queries[i][1];

        // Find source and destination nodes
        int srcIndex = findVariableIndex(src, nodes, numNodes);
        int destIndex = findVariable
