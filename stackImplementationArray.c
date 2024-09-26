#include <stdio.h>
#include<conio.h>
int top = -1;  // declaring the value of top = -1 globally
int size;

void push(int value, int stack[]) { 
    // Function to push an element into the stack
    if (top == size - 1) {
        printf("\nStack Overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

void pop(int stack[]) { 
    // Function to pop an element from the stack
    if (top == -1) {
        printf("\nStack Underflow\n");
    } else {
        printf("\n%d popped from stack\n", stack[top]);
        top--;
    }
}

int peek(int stack[]) { 
    // Function to peek the top element
    if (top == -1) {
        printf("\nStack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

void main() {
    int ele;
    int choice=0;
    printf("Enter the size of Stack: ");
    scanf("%d", &size);
    int stack[size];  // Create stack with user-defined size
    while(choice!=4){
        printf("\nChoose one of the following:\n");
        printf("1.Push\n");
        printf("2.pop\n");
        printf("3.Peek\n");
        printf("4.Exit\n");
        printf("Enter Your Choice:");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                for(int i=0;i<size;i++){
                    printf("\n Enter Element:");
                    scanf("%d",&ele);
                    push(ele,stack);
                }
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                printf("\nTop element is %d\n", peek(stack));
                break;
            case 4:
                printf("Successfully Exited");
                break;
        }
    }
}