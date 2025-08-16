// Mini Project 1 made using BlackBox AI
// Code not working

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int s_top = -1;
char stack[MAX_SIZE][MAX_SIZE]; // Stack to hold text states

void push(const char *text) {
    if (s_top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        s_top++;
        strcpy(stack[s_top], text); // Save the current state
    }
}

void pop(char *text) {
    if (s_top < 0) {
        printf("No previous state to undo\n");
        // Do not clear the text; retain the current text
    } else {
        strcpy(text, stack[s_top]); // Revert to the last state
        s_top--;
    }
}

void display(const char *text) {
    printf("Current text: %s\n", text);
}

int main() {
    char text[MAX_SIZE] = ""; // Current text
    char temp[MAX_SIZE]; // Temporary variable for undo
    int choice;

    while (1) {
        printf("\n1. Edit Text\n2. Undo\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after choice input

        switch (choice) {
            case 1:
                push(text); // Save the current state before editing
                printf("Enter new text: ");
                fgets(text, MAX_SIZE, stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline character
                break;
            case 2:
                pop(temp); // Revert to the last state
                if (s_top >= 0) {
                    strcpy(text, temp);
                }
                break;
            case 3:
                display(text);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
