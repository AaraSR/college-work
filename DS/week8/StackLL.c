#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int new_data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = new_data;
    newNode->next = NULL;

    return newNode;
}

int main(void) {
    struct Node* top = createNode(10);


    return 0;
}