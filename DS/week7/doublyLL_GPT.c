#include <stdio.h>
#include <stdlib.h>

// Define struct Node for Doubly Linked List
struct Node {
    int data;
        struct Node* next;
            struct Node* prev;
            };

            // Function to create a new node
            struct Node* createNode(int new_data) {
                struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
                    new_node->data = new_data;
                        new_node->next = NULL;
                            new_node->prev = NULL;
                                return new_node;
                                }

                                // Function to display the doubly linked list
                                void display(struct Node* head) {
                                    if (head == NULL) {
                                            printf("Linked List is empty!\n");
                                                    return;
                                                        }

                                                            printf("HEAD <-> ");
                                                                while (head != NULL) {
                                                                        printf("%d <-> ", head->data);
                                                                                head = head->next;
                                                                                    }
                                                                                        printf("NULL\n");
                                                                                        }

                                                                                        // Insert at front
                                                                                        struct Node* insertAtFront(struct Node* head, int new_data) {
                                                                                            struct Node* new_node = createNode(new_data);
                                                                                                new_node->next = head;

                                                                                                    if (head != NULL)
                                                                                                            head->prev = new_node;

                                                                                                                return new_node;
                                                                                                                }

                                                                                                                // Insert at end
                                                                                                                struct Node* insertAtEnd(struct Node* head, int new_data) {
                                                                                                                    struct Node* new_node = createNode(new_data);

                                                                                                                        if (head == NULL)
                                                                                                                                return new_node;

                                                                                                                                    struct Node* last = head;
                                                                                                                                        while (last->next != NULL)
                                                                                                                                                last = last->next;

                                                                                                                                                    last->next = new_node;
                                                                                                                                                        new_node->prev = last;

                                                                                                                                                            return head;
                                                                                                                                                            }

                                                                                                                                                            // Insert at a specific position (1-based index)
                                                                                                                                                            struct Node* insertAtPos(struct Node* head, int pos, int new_data) {
                                                                                                                                                                if (pos < 1) return head;

                                                                                                                                                                    if (pos == 1)
                                                                                                                                                                            return insertAtFront(head, new_data);

                                                                                                                                                                                struct Node* curr = head;
                                                                                                                                                                                    for (int i = 1; i < pos - 1 && curr != NULL; i++) {
                                                                                                                                                                                            curr = curr->next;
                                                                                                                                                                                                }

                                                                                                                                                                                                    if (curr == NULL) return head;

                                                                                                                                                                                                        struct Node* new_node = createNode(new_data);
                                                                                                                                                                                                            new_node->next = curr->next;
                                                                                                                                                                                                                new_node->prev = curr;

                                                                                                                                                                                                                    if (curr->next != NULL)
                                                                                                                                                                                                                            curr->next->prev = new_node;

                                                                                                                                                                                                                                curr->next = new_node;

                                                                                                                                                                                                                                    return head;
                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                    // Delete head node
                                                                                                                                                                                                                                    struct Node* deleteHead(struct Node* head) {
                                                                                                                                                                                                                                        if (head == NULL)
                                                                                                                                                                                                                                                return NULL;

                                                                                                                                                                                                                                                    struct Node* temp = head;
                                                                                                                                                                                                                                                        head = head->next;

                                                                                                                                                                                                                                                            if (head != NULL)
                                                                                                                                                                                                                                                                    head->prev = NULL;

                                                                                                                                                                                                                                                                        free(temp);
                                                                                                                                                                                                                                                                            return head;
                                                                                                                                                                                                                                                                            }

                                                                                                                                                                                                                                                                            // Delete last node
                                                                                                                                                                                                                                                                            struct Node* deleteLastNode(struct Node* head) {
                                                                                                                                                                                                                                                                                if (head == NULL)
                                                                                                                                                                                                                                                                                        return NULL;

                                                                                                                                                                                                                                                                                            if (head->next == NULL) {
                                                                                                                                                                                                                                                                                                    free(head);
                                                                                                                                                                                                                                                                                                            return NULL;
                                                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                                                    struct Node* last = head;
                                                                                                                                                                                                                                                                                                                        while (last->next != NULL)
                                                                                                                                                                                                                                                                                                                                last = last->next;

                                                                                                                                                                                                                                                                                                                                    last->prev->next = NULL;
                                                                                                                                                                                                                                                                                                                                        free(last);

                                                                                                                                                                                                                                                                                                                                            return head;
                                                                                                                                                                                                                                                                                                                                            }

                                                                                                                                                                                                                                                                                                                                            // Delete node at specific position
                                                                                                                                                                                                                                                                                                                                            struct Node* deleteNode(struct Node* head, int pos) {
                                                                                                                                                                                                                                                                                                                                                if (head == NULL || pos < 1)
                                                                                                                                                                                                                                                                                                                                                        return head;

                                                                                                                                                                                                                                                                                                                                                            if (pos == 1)
                                                                                                                                                                                                                                                                                                                                                                    return deleteHead(head);

                                                                                                                                                                                                                                                                                                                                                                        struct Node* curr = head;
                                                                                                                                                                                                                                                                                                                                                                            for (int i = 1; i < pos && curr != NULL; i++)
                                                                                                                                                                                                                                                                                                                                                                                    curr = curr->next;

                                                                                                                                                                                                                                                                                                                                                                                        if (curr == NULL)
                                                                                                                                                                                                                                                                                                                                                                                                return head;

                                                                                                                                                                                                                                                                                                                                                                                                    if (curr->prev != NULL)
                                                                                                                                                                                                                                                                                                                                                                                                            curr->prev->next = curr->next;

                                                                                                                                                                                                                                                                                                                                                                                                                if (curr->next != NULL)
                                                                                                                                                                                                                                                                                                                                                                                                                        curr->next->prev = curr->prev;

                                                                                                                                                                                                                                                                                                                                                                                                                            free(curr);
                                                                                                                                                                                                                                                                                                                                                                                                                                return head;
                                                                                                                                                                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                                                                                                                                                                // Main function to test
                                                                                                                                                                                                                                                                                                                                                                                                                                int main(void) {
                                                                                                                                                                                                                                                                                                                                                                                                                                    struct Node* head = NULL;

                                                                                                                                                                                                                                                                                                                                                                                                                                        // Test cases
                                                                                                                                                                                                                                                                                                                                                                                                                                            head = insertAtEnd(head, 10);
                                                                                                                                                                                                                                                                                                                                                                                                                                                head = insertAtEnd(head, 20);
                                                                                                                                                                                                                                                                                                                                                                                                                                                    head = insertAtEnd(head, 30);
                                                                                                                                                                                                                                                                                                                                                                                                                                                        head = insertAtFront(head, 5);
                                                                                                                                                                                                                                                                                                                                                                                                                                                            head = insertAtPos(head, 3, 15); // insert 15 at position 3

                                                                                                                                                                                                                                                                                                                                                                                                                                                                printf("Doubly Linked List after insertions:\n");
                                                                                                                                                                                                                                                                                                                                                                                                                                                                    display(head);

                                                                                                                                                                                                                                                                                                                                                                                                                                                                        head = deleteHead(head);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            printf("After deleting head:\n");
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                display(head);

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    head = deleteLastNode(head);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        printf("After deleting last node:\n");
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            display(head);

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                head = deleteNode(head, 2); // delete node at position 2
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    printf("After deleting node at position 2:\n");
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        display(head);

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            return 0;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            