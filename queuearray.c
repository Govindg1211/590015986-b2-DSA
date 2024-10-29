#include <stdio.h>
#include <conio.h>

int front = -1; 
int rear = -1;   
int size;

void enqueue(int value, int queue[]) { 
    if (rear == size - 1) {
        printf("\nQueue Overflow\n");
    } else {
        if (front == -1) {
            front = 0; 
        }
        rear++;
        queue[rear] = value;
        printf("%d enqueued into queue\n", value);
    }
}

void dequeue(int queue[]) { 
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow\n");
    } else {
        printf("\n%d dequeued from queue\n", queue[front]);
        front++;
    }
}

int peek(int queue[]) { 
    if (front == -1 || front > rear) {
        printf("\nQueue is empty\n");
        return -1;
    } else {
        return queue[front];
    }
}

void IsEmpty(int queue[]) {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nQueue is not empty\n");
    }
}

void IsFull(int queue[]) {
    if (rear == size - 1) {
        printf("\nQueue is full\n");
    } else {
        printf("\nQueue is not full\n");
    }
}

void main() {
    int ele;
    int choice = 0;
    printf("Enter the size of Queue: ");
    scanf("%d", &size);
    int queue[size];  

    while (choice != 6) {
        printf("\nChoose one of the following:\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Is empty\n");
        printf("5.Is full\n");
        printf("6.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Element: ");
                scanf("%d", &ele);
                enqueue(ele, queue);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                printf("\nFront element is %d\n", peek(queue));
                break;
            case 4:
                IsEmpty(queue);
                break;
            case 5:
                IsFull(queue);
                break;
            case 6:
                printf("Successfully Exited\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}