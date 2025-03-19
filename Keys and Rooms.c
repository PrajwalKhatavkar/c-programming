#include <stdbool.h>
#include <stdlib.h>

void dfs(int** rooms, int* visited, int room) {
    if (visited[room]) return;
    visited[room] = 1;
    int* keys = rooms[room];
    for (int i = 0; keys[i] != -1; ++i) {
        dfs(rooms, visited, keys[i]);
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int* visited = (int*)malloc(sizeof(int) * roomsSize);
    for (int i = 0; i < roomsSize; ++i) {
        visited[i] = 0;
    }
    dfs(rooms, visited, 0);
    for (int i = 0; i < roomsSize; ++i) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }
    free(visited);
    return true;
}

int main() {
    int roomsSize1 = 4;
    int* roomsColSize1 = (int*)malloc(sizeof(int) * roomsSize1);
    int* rooms1[] = {
        (int[]){1, -1},
        (int[]){2, -1},
        (int[]){3, -1},
        (int[]){-1}
    };
    printf("Example 1 output: %s\n", canVisitAllRooms(rooms1, roomsSize1, roomsColSize1) ? "true" : "false");
    
    int roomsSize2 = 4;
    int* roomsColSize2 = (int*)malloc(sizeof(int) * roomsSize2);
    int* rooms2[] = {
        (int[]){1, 3, -1},
        (int[]){3, 0, 1, -1},
        (int[]){2, -1},
        (int[]){0, -1}
    };
    printf("Example 2 output: %s\n", canVisitAllRooms(rooms2, roomsSize2, roomsColSize2) ? "true" : "false");
    
    free(roomsColSize1);
    free(roomsColSize2);

    return 0;
}
