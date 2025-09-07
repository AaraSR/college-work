#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void traverseList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf("\n");

    // Free allocated memory (optional but recommended)
    temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
}

int main() {
    // Create the first node (head of the list)
    Node* head = createNode(10);

    // Create and link the second node
    head->next = createNode(20);
    head->next->prev = head;

    // Create and link the third node
    head->next->next = createNode(30);
    head->next->next->prev = head->next;

    // Create and link the fourth node
    head->next->next->next = createNode(40);
    head->next->next->next->prev = head->next->next;


    return 0;
}