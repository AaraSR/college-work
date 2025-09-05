#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Check if stack is empty
int isEmpty(struct Node* head) {
    return head == NULL;
}

// Push an element onto stack
void push(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void pop(struct Node** head) {

}




// // // // main() func
int main(void) {
    struct Node* head = createNode(10);
    push(head, 20);


    return 0;
}