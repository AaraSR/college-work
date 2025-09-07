#include <stdio.h>
#include <stdlib.h>

// define struct Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int new_data, struct Node* head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = new_data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

