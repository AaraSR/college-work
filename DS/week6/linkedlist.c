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
        printf("Linked List is empty!\n");
        return;
    }
    
    printf("HEAD -> ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
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

// deleting head node
struct Node* deleteHead(struct Node* head) {
    
    // if list is empty
    if (head == NULL) {
        return NULL;
    }

    // store HEAD in TEMP var
    struct Node* temp = head;

    // move HEAT ptr to NEXT node OR append the HEAD ptr to NEXT node ka DATA
    head = head->next;

    // free the memory of old head (which is TEMP)
    free(temp);

    return head;
}

// delete last node
struct Node* deleteLastNode(struct Node* head) {

    // check if empty
    if (head == NULL) {
        return NULL;
    }

    // if HEAD has only one node, delete that
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // find penultimate or second last node
    struct Node* second_last = head;
    while(second_last->next->next != NULL) { // SecondLast's NEXT(the last one)'s NEXT will be NULL 
        second_last = second_last->next;
    }

    // first delete the last node
    free(second_last->next);

    // then update SecondLast's NEXT to be NULL (bcoz it will be last now)
    second_last->next = NULL;

    return head;
}

struct Node* deleteNode(struct Node* head, int pos) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    // if LL is empty
    if (temp == NULL) {return head; }

    // if pos = 1 ie. HEAD
    if (pos == 1) {
        deleteHead(head);
    }

    // traverse till pos
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    // pos is found when temp != NULL, so delete that node
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Data not present\n");
    }

    return head;
}

// // // // main() function

int main(void) {
    struct Node* head = NULL;

    
    return 0;
}