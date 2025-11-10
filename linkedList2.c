//
// Created by PREM on 10-11-2025.
//

#include <stdio.h>
#include <stdlib.h>

// --- Node Structure (Same as before) ---
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// --- Function Prototypes (Updated) ---
void insertAtEnd(int newData);
void deleteFromFront();
void printList();

// --- 1. Insert at End ---
void insertAtEnd(int newData) {
    // Step 1: Create the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = newData;
    newNode->next = NULL; // The new node is the END, so it points to NULL

    // Step 2: Find the end of the list to attach it

    // Case 1: The list is currently empty
    if (head == NULL) {
        head = newNode; // The new node is now the first (and only) node
        printf("Inserted %d at the end (list was empty).\n", newData);
        return;
    }

    // Case 2: The list is NOT empty
    // We need a 'walker' pointer to find the last node
    struct Node* current = head;

    // Walk the list until we find the *last* node
    // The last node is the one whose 'next' is NULL
    while (current->next != NULL) {
        current = current->next;
    }

    // Step 3: Attach the new node
    // 'current' is now pointing to the last node
    current->next = newNode;
    printf("Inserted %d at the end.\n", newData);
}

// --- 2. Delete from Front ---
void deleteFromFront() {
    // Case 1: List is empty
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    // Case 2: List has nodes
    int deletedData = head->data;

    // Store the node we are about to delete in a temporary key
    struct Node* temp = head;

    // Move the 'head' key to the *next* node in the list
    head = head->next; // or head = temp->next;

    // Free the old first node's memory
    free(temp);

    printf("Deleted %d from the front.\n", deletedData);
}

// --- Utility: Print the List (Same as before) ---
void printList() {
    struct Node* current = head;
    if (current == NULL) {
        printf("List: (Empty)\n");
        return;
    }

    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// --- Main Function for Testing (Updated) ---
int main() {
    printf("--- Initial State ---\n");
    printList();

    // Test Insert at End
    printf("\n--- Insert Operations ---\n");
    insertAtEnd(10);  // List: 10 -> NULL
    insertAtEnd(20);  // List: 10 -> 20 -> NULL
    insertAtEnd(30);  // List: 10 -> 20 -> 30 -> NULL
    printList();

    // Test Delete from Front
    printf("\n--- Delete Operations ---\n");
    deleteFromFront();    // List: 20 -> 30 -> NULL
    printList();

    deleteFromFront();    // List: 30 -> NULL
    printList();

    deleteFromFront();    // List: (Empty)
    printList();

    deleteFromFront();    // Testing empty list case

    return 0;
}