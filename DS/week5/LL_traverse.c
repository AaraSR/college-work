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

int main(void) {
    int n, i, elem, choice;
    struct Node* head = NULL;

    printf("Create a Linked List!\nEnter the no. of elements to of Linked List: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("List is empty!");
        return 0;
    }

    printf("Enter the elements\n");

    for (i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &elem);
        addNode(&head, elem);
    }

    printf("Print LL using:\n1. Recursive method\n2. Iterative method\nChoice: ");
    scanf("%d", &choice);
    
    switch (choice)
    {
    case 1:
        printListR(head);
        break;
    
    case 2:
        printListIt(head);
        break;
    
    default:
        printf("Enter a valid choice!");
        break;
    }

    return 0;
}