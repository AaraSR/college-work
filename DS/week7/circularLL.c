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
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("HEAD -> ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// inserting node at end and linking it to HEAD
void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        newNode->next = newNode;  // linking to itself when LL is empty
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next != *head_ref) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head_ref;
}

int main(void) {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    traverseList(head);

    return 0;
}