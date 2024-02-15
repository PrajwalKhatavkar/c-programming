#include <stdbool.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

TrieNode* trieNodeCreate() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

typedef struct {
    TrieNode* root;
} Trie;

Trie* trieCreate() {
    Trie* obj = (Trie*)malloc(sizeof(Trie));
    obj->root = trieNodeCreate();
    return obj;
}

void trieInsert(Trie* obj, char * word) {
    TrieNode* current = obj->root;
    while (*word != '\0') {
        int index = *word - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = trieNodeCreate();
        }
        current = current->children[index];
        word++;
    }
    current->isEndOfWord = true;
}

bool trieSearch(Trie* obj, char * word) {
    TrieNode* current = obj->root;
    while (*word != '\0') {
        int index = *word - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
        word++;
    }
    return current->isEndOfWord;
}

bool trieStartsWith(Trie* obj, char * prefix) {
    TrieNode* current = obj->root;
    while (*prefix != '\0') {
        int index = *prefix - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
        prefix++;
    }
    return true;
}

void trieFree(Trie* obj) {
    // Free memory recursively
    free(obj);
}

int main() {
    Trie* trie = trieCreate();
    trieInsert(trie, "apple");
    bool search1 = trieSearch(trie, "apple");   // return True
    bool search2 = trieSearch(trie, "app");     // return False
    bool startsWith = trieStartsWith(trie, "app"); // return True
    trieInsert(trie, "app");
    bool search3 = trieSearch(trie, "app");     // return True

    // Print results
    printf("Search 1: %s\n", search1 ? "True" : "False");
    printf("Search 2: %s\n", search2 ? "True" : "False");
    printf("Starts with 'app': %s\n", startsWith ? "True" : "False");
    printf("Search 3: %s\n", search3 ? "True" : "False");

    trieFree(trie); // Free memory
    return 0;
}
