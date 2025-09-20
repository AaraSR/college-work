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

void display(struct Node* head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Push an element onto stack
void push(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;

    display(*head);
}

int pop(struct Node** head) {
    if (isEmpty(*head)) {
        printf("Stack Underflow\n");
        return -1;  // or some error code
    }
    struct Node* temp = *head;
    int popped_data = temp->data;
    *head = temp->next;
    free(temp);

    display(*head);

    return popped_data;
}

// // // // main() func
int main(void) {
    struct Node* head = NULL;
    push(&head, 20);
    push(&head, 10);

    return 0;
}