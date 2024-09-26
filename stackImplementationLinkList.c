#include <stdio.h>
#include<stdlib.h>
// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Initialize the top of the stack as NULL
struct Node* top = NULL;

// Function to push an element onto the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nStack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top; // Point new node to previous top
    top = newNode;       // Update top to new node
    printf("%d pushed into stack\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
        return;
    }
    struct Node* temp = top; // Store current top
    printf("\n%d popped from stack\n", temp->data);
    top = top->next; // Move top pointer to next node
    free(temp); // Free memory of popped node
}

// Function to peek at the top element of the stack
int peek() {
    if (top == NULL) {
        printf("\nStack is empty\n");
        return -1;
    }
    return top->data; // Return data of top node
}

// Main function to demonstrate stack operations
int main() {
    int ele;
    int choice = 0;

    while (choice != 4) {
        printf("\nChoose one of the following:\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Element: ");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("\nTop element is %d\n", peek());
                break;
            case 4:
                printf("Successfully Exited\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}