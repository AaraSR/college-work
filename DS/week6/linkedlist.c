#include <stdio.h>
#include <stdlib.h>

//Defining the Node
struct Node {
    int data;
    struct Node* next; 
}; 


struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
};

//Print list using Recursive Method
void traverseList(struct Node* head) {
    if(head == NULL) {
        printf("\n");
        return;
    }

    printf("%d ", head->data);
    traverseList(head->next);
};

//Print list using Iterative Method
void traverseList1(struct Node* head) {
    struct Node* curr = head;
    
    printf("\nList:\n");
    while(curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

//Searching the Key in node
int searchKey(struct Node* head, int key) {
    struct Node* curr = head;

    if(curr == NULL) {
        return 0;
    }

    if(curr->data == key){
        return 1;
    }

    return searchKey(curr->next, key);
}

struct Node* insertPos(struct Node* head, int pos, int data) {
    if(pos<1) {
        return head;
    }

    if(pos == 1) {
        struct Node *newNode = createNode(data);
        newNode->next = head;
        return newNode;
    }

    //If pos is not 1
    struct Node* curr = head;

    for(int i = 1; i < pos-1 && curr != NULL; i++) {
        curr = curr->next;
    }

    if(curr == NULL) {
        return head;
    }

    struct Node* newNode = createNode(data);
    
    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

struct Node* deletePos(struct Node* head, int pos) {
    //if position is 1
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    //if position is not 1, we need to get our pointer to that user position
    struct Node* curr = head;
    for(int i = 1; i < pos-1 && curr->next != NULL; i++) {
        curr = curr->next;
    }

    if (curr->next == NULL) {
        return head; 
    }
    

    struct Node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);

    return head;

}

void printList(struct Node* head) {
    struct Node* curr = head;
    printf("\nList: \n");
    while(curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

int main () {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("\nWelcome to Linked List Program!");
    printList(head);

    int user_choice;
    int user_pos;
    int user_data;

    while(1) {
        printf("\nWhat would you like to do?");
        printf("\n1. Insert \n2. Delete \n0. To Exit -->");
        printf("\nEnter choice: ");
        scanf("%d", &user_choice);

        switch(user_choice) {
            case 0:
                printf("Exiting Program...");
                return 0;
            case 1:
                printf("\nEnter position of Insertion: ");
                scanf("%d", &user_pos);
                printf("\nEnter data to insert: ");
                scanf("%d", &user_data);
                head = insertPos(head, user_pos, user_data);
                printList(head);
                break;
            case 2:
                printf("\nEnter position of Deletion: ");
                scanf("%d", &user_pos);
                head = deletePos(head, user_pos);
                printList(head);
                break;
            default:
                printf("\nInvalid Choice.");
                break;
        }
    }
    
}