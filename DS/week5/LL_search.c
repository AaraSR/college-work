#include <stdio.h>
#include <stdlib.h>

// linked list struct node
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

// searching func using Recursion
int searchNodeR(struct Node* head, int element) {

    if (head == NULL) {
        printf("Linked List is empty!");
        return 0;
    }

    else if (head->data == element) {
        printf("Element %d found in Linked List.", element);
        return 1;
    }

    return searchNode(head->next, element);
}

// searching func using Iteration
int searchNodeIt(struct Node* head, int element) {
    
}

int main(void) {

    return 0;
}