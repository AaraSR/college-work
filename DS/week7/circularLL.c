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

// travelling and printing/displaying using iteration
void display(struct Node* head) {
    if (head->data == NULL) {
        
    }
}

int main(void) {

    return 0;
}