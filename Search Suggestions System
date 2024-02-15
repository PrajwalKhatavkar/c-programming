#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26
#define MAX_PRODUCTS 3

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
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

void trieInsert(Trie* obj, char* word) {
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

void trieSuggestProducts(Trie* obj, char* searchWord, char** products, int productsSize, char*** suggestions, int* returnSize) {
    TrieNode* current = obj->root;
    char prefix[1001] = "";
    int len = strlen(searchWord);
    *returnSize = 0;

    for (int i = 0; i < len; i++) {
        int index = searchWord[i] - 'a';
        if (current->children[index] == NULL) {
            break;
        }
        current = current->children[index];
        prefix[i] = searchWord[i];
        prefix[i + 1] = '\0';

        char** suggestedProducts = (char**)malloc(sizeof(char*) * MAX_PRODUCTS);
        int count = 0;
        for (int j = 0; j < ALPHABET_SIZE && count < MAX_PRODUCTS; j++) {
            if (current->children[j] != NULL) {
                char nextPrefix[1001];
                strcpy(nextPrefix, prefix);
                nextPrefix[i + 1] = j + 'a';
                nextPrefix[i + 2] = '\0';
                trieDFS(current->children[j], nextPrefix, products, productsSize, &count, suggestedProducts);
            }
        }
        suggestions[*returnSize] = suggestedProducts;
        (*returnSize)++;
    }
}

void trieDFS(TrieNode* node, char* prefix, char** products, int productsSize, int* count, char** suggestedProducts) {
    if (*count >= MAX_PRODUCTS || node == NULL) {
        return;
    }
    if (node->isEndOfWord) {
        suggestedProducts[*count] = (char*)malloc(sizeof(char) * 1001);
        strcpy(suggestedProducts[*count], prefix);
        (*count)++;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != NULL) {
            char nextPrefix[1001];
            strcpy(nextPrefix, prefix);
            nextPrefix[strlen(prefix)] = i + 'a';
            nextPrefix[strlen(prefix) + 1] = '\0';
            trieDFS(node->children[i], nextPrefix, products, productsSize, count, suggestedProducts);
        }
    }
}

int main() {
    Trie* trie = trieCreate();
    char* products[] = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    int productsSize = sizeof(products) / sizeof(products[0]);
    for (int i = 0; i < productsSize; i++) {
        trieInsert(trie, products[i]);
    }

    char* searchWord = "mouse";
    char** suggestions[1001];
    int returnSize;
    trieSuggestProducts(trie, searchWord, products, productsSize, suggestions, &returnSize);

    // Output suggestions
    for (int i = 0; i < returnSize; i++) {
        printf("Suggestions after typing %.*s: [", i + 1, searchWord);
        for (int j = 0; j < MAX_PRODUCTS; j++) {
            printf("%s", suggestions[i][j]);
            if (j < MAX_PRODUCTS - 1) {
                printf(", ");
           
