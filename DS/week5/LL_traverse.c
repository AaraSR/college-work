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

// traversing LL using Recursion
void traverseListR(struct Node* head) {

    if (head == NULL) {
        printf("\n");
        return;
    }

    printf("%d ", head->data);

    traverseListR(head->next);
}

// // traversing LL using Iteration
// void traverseListIt(struct Node* head) {

//     while (head = '\0') {
        
//     }
// }

int main(void) {
    
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    
    printf("Linked List: ");
    traverseListR(head);

    return 0;
}