#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

struct Node* createTerm(int c, int p) {
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;
    
    return newNode;
}

void printList(struct Node* head) {
    struct Node* curr = head;

    while (curr != NULL) {
        printf("%d x^%d ", curr->coeff, curr->pow);
        curr = curr->next;
    }
    printf("= 0\n");
}

struct Node* addPolynomials(struct Node* headX, struct Node* headY) {
    
}