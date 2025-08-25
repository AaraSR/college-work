#include <stdio.h>
#include <stdlib.h>

// define struct Node
struct Node {
    int data;
    struct Node* next;
};

// createNode func
struct Node* createNode(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = NULL;

    return new_node;
}

// insert at 'pos'
struct Node* insertAtPos(struct Node *last, int data, int pos) {
    if (last == NULL) {
        if (pos != 1) {
            printf("Invalid position!\n");
            return last;
        }

        struct Node *newNode = createNode(data);
        last = newNode;
        last->next = last;

        return last;
    }

    struct Node *newNode = createNode(data);

    struct Node *curr = last->next;

    // when pos = 1, Node->
    if (pos == 1) {
        newNode->next = curr;
        last->next = newNode;

        return last;
    }

    // traverse to reach pos
}
