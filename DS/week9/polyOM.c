#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    int prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;
struct Node* head2 = NULL;
struct Node* tail2 = NULL;
struct Node* head3 = NULL;
struct Node* tail3 = NULL;

void createPoly1(int coefficient, int degree) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = degree;
    newNode->prev = coefficient;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void createPoly2(int coefficient, int degree) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = degree;
    newNode->prev = coefficient;
    newNode->next = NULL;

    if(head2 == NULL) {
        newNode->next = NULL;
        head2 = newNode;
        tail2 = newNode;
    }
    else {
        tail2->next = newNode;
        tail2 = newNode;
    }
}

void createAddedPoly(int coefficient, int degree) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = degree;
    newNode->prev = coefficient;
    newNode->next = NULL;

    if(head3 == NULL) {
        newNode->next = NULL;
        head3 = newNode;
        tail3 = newNode;
    }
    else {
        tail3->next = newNode;
        tail3 = newNode;
    }
}

void display() {
    if(head == NULL) {
        printf("\nList is Empty!");
        return;
    }

    struct Node* curr = head;

    printf("\nPolynomial 1 (coeff, deg): ");
    while(curr != NULL) {
        if(curr == head) {
            printf("(%d, %d)", curr->prev, curr->data);
        }
        else {
            printf(" -> (%d, %d)", curr->prev, curr->data);
        }
        curr = curr->next;
    }

    struct Node* curr2 = head2;
    printf("\nPolynomial 2 (coeff, deg): ");
    while(curr2 != NULL) {
        if(curr2 == head2) {
            printf("(%d, %d)", curr2->prev, curr2->data);
        }
        else {
            printf(" -> (%d, %d)", curr2->prev, curr2->data);
        }
        curr2 = curr2->next;
    }

    struct Node* curr3 = head3;
    printf("\nAdded Polynomial (coeff, deg): ");
    while(curr3 != NULL) {
        if(curr3 == head3) {
            printf("(%d, %d)", curr3->prev, curr3->data);
        }
        else {
            printf(" -> (%d, %d)", curr3->prev, curr3->data);
        }
        curr3 = curr3->next;
    }
}

void addPoly() {
    struct Node* curr = head;
    struct Node* curr2 = head2;
    
    while(curr != NULL && curr2 != NULL) {
        if(curr->data == curr2->data) {
            createAddedPoly(curr->prev + curr2->prev, curr->data);
            //if degree is equal, both pointers move
            curr = curr->next;
            curr2 = curr2->next;
        }
        else if(curr->data > curr2->data) {  
            createAddedPoly(curr->prev, curr->data);
            //Only one pointer moves ahead, if degree is different
            curr = curr->next;
        }
        else {
            createAddedPoly(curr2->prev, curr2->data);
            //Same here
            curr2 = curr2->next;
        }
    }

    while(curr != NULL) {
        //add remaining polynomials from Poly 1
        createAddedPoly(curr->prev, curr->data);
        curr = curr->next;
    }

    while(curr2 != NULL) {
        //add remaining polynomials from Poly 2
        createAddedPoly(curr2->prev, curr2->data);
        curr2 = curr2->next;
    }
}

int main () {
    createPoly1(6, 4);
    createPoly1(9, 3);
    createPoly1(8, 2);
    createPoly1(7, 1);

    createPoly2(10, 3);
    createPoly2(7, 2);
    createPoly2(3, 0);

    addPoly();
    display();
}