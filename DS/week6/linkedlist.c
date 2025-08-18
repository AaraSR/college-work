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

// func to add a node
void addNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;

    // if the 'next' ptr has NULL, create a new node 
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // if the 'next' ptr has other node, go on (while loop) till we reach the last node
    while (last->next != NULL) {
        last = last->next;
    }
    // then create a new node there
    last->next = new_node;
}

// traversing & printing LL using Recursion
void printListR(struct Node* head) {

    if (head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    printf("%d -> ", head->data);

    printListR(head->next);
}

// traversing & printing LL using Iteration
void printListIt(struct Node* head) {
    
    if (head == NULL) {
        printf("Linked List is empty!");
    }
    
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("\n");
}