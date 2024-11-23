#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int binaryTree[MAX];
void insertArray(int index, int value) {
    if (index < MAX) {
        binaryTree[index] = value;
    }
}
void preOrder(int index) {
    if (index >= MAX || binaryTree[index] == 0) return;
    printf("%d ", binaryTree[index]);
    preOrder(2 * index + 1); 
    preOrder(2 * index + 2); 
}
void inOrderArray(int index) {
    if (index >= MAX || binaryTree[index] == 0) return;

    inOrderArray(2 * index + 1); 
    printf("%d ", binaryTree[index]);
    inOrderArray(2 * index + 2); 
}
void postOrder(int index) {
    if (index >= MAX || binaryTree[index] == 0) return;
    postOrder(2 * index + 1); 
    postOrder(2 * index + 2);
    printf("%d ", binaryTree[index]);
}
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}
void preOrderLinked(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderLinked(root->left);
        preOrderLinked(root->right);
    }
}
void inOrderLinked(struct Node* root) {
    if (root != NULL) {
        inOrderLinked(root->left);
        printf("%d ", root->data);
        inOrderLinked(root->right);
    }
}
void postOrderLinked(struct Node* root) {
    if (root != NULL) {
        postOrderLinked(root->left);
        postOrderLinked(root->right);
        printf("%d ", root->data);
    }
}
struct QueueNode {
   struct Node* treeNode;
   struct QueueNode* next;
};
struct Queue {
   struct QueueNode* front;
   struct QueueNode* rear;
};
struct Queue* createQueue() {
   struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
   q->front = q->rear = NULL;
   return q;
}
void enqueue(struct Queue* q, struct Node* node) {
   struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
   temp->treeNode = node;
   temp->next = NULL;
   if (q->rear == NULL) { 
       q->front = q->rear = temp; 
       return; 
   }
   q->rear->next = temp; 
   q->rear = temp; 
}
struct Node* dequeue(struct Queue* q) {
   if (q->front == NULL)
       return NULL;
   struct QueueNode* temp = q->front;
   struct Node* node = temp->treeNode;
   q->front = q->front->next;
   if (q->front == NULL)
       q->rear = NULL;
   free(temp);
   return node;
}
void levelOrderTraversal(struct Node* root) {
   if (root == NULL)
       return;
   struct Queue* q = createQueue();
   enqueue(q, root);
   while (q->front != NULL) {
       struct Node* current = dequeue(q);
       printf("%d ", current->data);
       if (current->left != NULL)
           enqueue(q, current->left);
       if (current->right != NULL)
           enqueue(q, current->right);
   }
}
int main() {
    printf("Binary Tree using Array Representation:\n");
    insertArray(0, 1); 
    insertArray(1, 2); 
    insertArray(2, 3); 
    insertArray(3, 4); 
    insertArray(4, 5); 
    printf("Pre-order Traversal: ");
    preOrder(0);
    printf("\nIn-order Traversal: ");
    inOrderArray(0);
    printf("\nPost-order Traversal: ");
    postOrder(0);
printf("\n\nBinary Tree using Linked List Representation:\n");
struct Node* root = NULL;
root = insert(root, 4);
insert(root, 2);
insert(root, 5);
insert(root, 1);
insert(root, 3);
printf("Pre-order Traversal: ");
preOrderLinked(root);
printf("\nIn-order Traversal: ");
inOrderLinked(root);
printf("\nPost-order Traversal: ");
postOrderLinked(root);
printf("\nLevel-order Traversal: ");
levelOrderTraversal(root);
return 0;
}