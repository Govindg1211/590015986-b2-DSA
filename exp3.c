#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype {
    int data;
    struct nodetype *next;
} node;

// Function to allocate memory for a new node
node *memory() {
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit if memory allocation fails
    }
    temp->next = NULL;
    return temp;
}

// Function to calculate the size of the linked list
int size(node *head) {
    int count = 0; // Initialize count to 0
    node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to display the linked list
void display(node *head) {
    printf("\n\tLinked List:\n");
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    
    node *temp = head;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node at the end of the linked list
node *insert_at_last(node *head) {
    node *new_node = memory();
    printf("Enter the number: ");
    scanf("%d", &new_node->data);
    
    if (head == NULL) {
        return new_node; // If the list is empty, return new node as head
    }
    
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the last node
    }
    
    temp->next = new_node; // Link the new node at the end
    return head;
}

// Function to insert a node at the beginning of the linked list
node *insert_at_first(node *head) {
    node *new_node = memory();
    printf("Enter the number: ");
    scanf("%d", &new_node->data);
    
    new_node->next = head; // Link new node to current head
    return new_node; // New node becomes the new head
}

// Function to insert a node at a specified position
node *insert_at_pos(node *head) {
    int pos, siz = size(head);
    
    printf("Enter the number: ");
    node *new_node = memory();
    scanf("%d", &new_node->data);
    
    printf("Enter the position you want to enter (1-based index): ");
    scanf("%d", &pos);
    
    if (pos < 1 || pos > siz + 1) { // Check for valid position
        printf("\nYou are trying to access an out-of-range element.\n");
        free(new_node); // Free allocated memory for invalid position
        return head;
    }

    if (pos == 1) { // Insert at beginning
        new_node->next = head;
        return new_node; // New node becomes the new head
    }

    node *temp = head;
    
    for (int i = 1; i < pos - 1; i++) { // Traverse to one position before desired position
        temp = temp->next;
    }
    
    new_node->next = temp->next; // Link new node to next node
    temp->next = new_node; // Link previous node to new node
    
    return head;
}

// Function to delete the last node of the linked list
node *del_last(node *head) {
    if (head == NULL) { // If list is empty, nothing to delete
        return head;
    }
    
    if (head->next == NULL) { // If only one element exists
        free(head); // Free memory of single element
        return NULL; // List becomes empty
    }

    node *temp = head;

    while (temp->next->next != NULL) { // Traverse to second last node
        temp = temp->next;
    }

    free(temp->next); // Free last node's memory
    temp->next = NULL; // Set second last's next to NULL

    return head;
}

// Function to delete the first node of the linked list
node *del_first(node *head) {
   if (head == NULL) { // If list is empty, nothing to delete
       return head;
   }

   node *temp = head; 
   head = head->next; // Move head pointer to next node
   free(temp); // Free memory of deleted first node

   return head; 
}

// Function to delete a specific node by its position
node *del_certain_node(node *head) {
   int n;

   printf("Enter the index of the node you want to delete (1-based index): ");
   scanf("%d", &n);

   if (n < 1 || n > size(head)) { // Check for valid index range
       printf("Index out of bound\n");
       return head;
   }

   if (n == 1) { 
       return del_first(head); // Delegate deletion of first node 
   }

   node *temp = head;

   for (int i = 1; i < n - 1; i++) { 
       temp = temp->next; 
   }

   node *to_delete = temp->next; 
   temp->next = to_delete->next; 
   free(to_delete); 

   return head; 
}

int main() { 
   node *head = NULL; 
   int choice;

   do { 
       printf("\nPress 0 for exit\nPress 1 for insert at last\nPress 2 for insert at first\nPress 3 for insert at position\nPress 4 for deleting last node\nPress 5 for deleting first node\nPress 6 for deleting certain nodes\nPress 7 for displaying all nodes\n"); 
       scanf("%d", &choice);

       switch (choice) { 
           case 1: 
               head = insert_at_last(head); 
               break; 
           case 2: 
               head = insert_at_first(head); 
               break; 
           case 3: 
               head = insert_at_pos(head); 
               break; 
           case 4: 
               head = del_last(head); 
               break; 
           case 5: 
               head = del_first(head); 
               break; 
           case 6: 
               head = del_certain_node(head); 
               break; 
           case 7: 
               display(head); 
               break; 
           default: 
               break; 
       } 

   } while (choice != 0); 

   return 0; // Return success status from main function.
}