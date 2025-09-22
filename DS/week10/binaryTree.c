#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create() {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    int data, choice;

    printf("\n\nPress 0 to exit\nPress 1 to create a new node of Binary Tree\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 0) {return 0; }
    else {
        printf("Enter the data: ");
        scanf("%d", &data);

        temp->data = data;

        printf("Enter the left child of Root Node %d", data);
        temp->left = create();

        printf("Enter the right child of Roode Node %d", data);
        temp->right = create();

        return temp;
    }
}

int main(void) {
    struct node* root;

    printf("BINARY TREE\n");
    root = create();

    return 0;
}