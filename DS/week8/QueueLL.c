#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// defining Queue struct
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// newNode func
struct Node* newNode(int new_data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = new_data;
    node->next = NULL;
    return node;
}

// createQueue func
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// traverse/print Q(LL)
void printQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Current Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// enQ in LL
void enqueue(struct Queue* q, int new_data) {
    struct Node* new_node = newNode(new_data);
    if (isEmpty(q)) {
        q->front = q->rear = new_node;
        printQueue(q);
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
    printQueue(q);
}

// deQ in LL
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return;
    }
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    printQueue(q);
}

// // // // main function
int main() {
    struct Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);

    dequeue(q);
    dequeue(q);

    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    
    return 0;
}