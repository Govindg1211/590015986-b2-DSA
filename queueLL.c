#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* front = NULL;
struct Node* rear = NULL;


void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nQueue Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL; 

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued into queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("\nQueue Underflow\n");
        return;
    }
    struct Node* temp = front; 
    printf("\n%d dequeued from queue\n", temp->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp); 
}


int peek() {
    if (front == NULL) {
        printf("\nQueue is empty\n");
        return -1;
    }
    return front->data; 
}

void IsEmpty() {
    if (front == NULL) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nQueue is not empty\n");
    }
}


int main() {
    int ele;
    int choice = 0;

    while (choice != 5) {
        printf("\nChoose one of the following:\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Is empty\n");
        printf("5.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Element: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("\nFront element is %d\n", peek());
                break;
            case 4:
                IsEmpty();
                break;
            case 5:
                printf("Successfully Exited\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}