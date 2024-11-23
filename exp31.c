#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int binaryTree[MAX];
void insert(int index, int value) {
    if (index < MAX) {
        binaryTree[index] = value;
    }
}
void display() {
    for (int i = 0; i < MAX && binaryTree[i] != 0; i++) {
        printf("%d ", binaryTree[i]);
    }
}
int main() {
    insert(0, 1); 
    insert(1, 2); 
    insert(2, 3);
    insert(3, 4); 
    insert(4, 5); 
    printf("Binary Tree (Array Representation): ");
    display();
    return 0;
}