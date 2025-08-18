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

// // traversing & printing LL using Recursion
// void printListR(struct Node* head) {

//     if (head == NULL) {
//         printf("Linked List is empty!\n");
//         return;
//     }

//     printf("%d -> ", head->data);

//     printListR(head->next);
// }

// traversing & printing(displaying) LL using Iteration
void display(struct Node* head) {
    
    if (head == NULL) {
        printf("Linked List is empty!");
    }
    
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

// // // // INSERTION FUNCTIONS

// func for inserting at FRONT (at the place of head)
struct Node* insertAtFront(struct Node* head, int new_data) {
    // creating new node
    struct Node* new_node = createNode(new_data);

    // new_node ka NEXT ptr is updated to head
    new_node->next = head;

    return new_node;
}

// func for inserting at END / appending (at the place of NULL ptr)
struct Node* insertAtEnd(struct Node* head, int new_data) {

    // make new node first
    struct Node* new_node = createNode(new_data);

    // if LL is empty, this new_node is the ONLY node this LL will have
    if (head == NULL) {
        return new_node;
    }

    // store 'head' ka reference in a temp variable 'last' which will go on till the end of the LL to append
    struct Node* last = head;

    // traverse till the end of LL
    while (last->next != NULL) {
        last = last->next;
    }

    // this last node's NEXT will be the 'new_node', which is appended
    last->next = new_node;
}

struct Node* insertAtPos(struct Node *head, int pos, int new_data) {

    // if position is -ve
    if (pos < 1) {
        return head;
    }

    // if pos == 1 (which is HEAD)
    if (pos == 1) {
        insertAtFront(head, new_data);
    }

    struct Node *curr = head;
    // if pos is somewhere in the middle
    for (int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if (curr == NULL) {return head;}

    // create the newNode now
    struct Node *new_node = createNode(new_data);

    // value of curr->next (the desired pos provided) will go to new_node->next 
    new_node->next = curr->next;
    // value of new_node(the data) will have the ptr of curr->next
    curr->next = new_node;

    return head;
}

// // // // DELETION FUNCTIONS

