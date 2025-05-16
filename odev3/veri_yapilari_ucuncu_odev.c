#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

TrieNode *createNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode *root, const char *word) {
    TrieNode *current = root;
    while (*word) {
        int index = *word - 'a';
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
        word++;
    }
    current->isEndOfWord = 1;
}

int search(TrieNode *root, const char *word) {
    TrieNode *current = root;
    while (*word) {
        int index = *word - 'a';
        if (!current->children[index]) return 0;
        current = current->children[index];
        word++;
    }
    return current->isEndOfWord;
}

int main() {
    TrieNode *root = createNode();
    insert(root, "merhaba");
    insert(root, "emre");
    insert(root, "beyza");

    printf("emre kelimesi %s\n", search(root, "emre") ? "bulundu" : "bulunamadı");
    printf("beyza kelimesi %s\n", search(root, "beyza") ? "bulundu" : "bulunamadı");
    printf("kral kelimesi %s\n", search(root, "kral") ? "bulundu" : "bulunamadı");
    return 0;
}
