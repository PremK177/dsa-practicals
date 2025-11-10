#include <stdio.h>
#include <stdlib.h>

// --- Node Structure ---
struct Node {
    int data;
    struct Node* next; //'next' is the pointer that points to the next node
};

// Global head pointer
struct Node* head = NULL; //'head' points at the head, initialized at NULL

// --- Function Prototypes ---
void insertAtFront(int newData);
void deleteFromEnd();
void printList();

// --- 1. Insert at Front ---
void insertAtFront(int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    /*
     * stores the new data in a temp var and assigns memory equal to a single node
     */
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = newData; // sets the data, node's int data is initialized
    newNode->next = head; // the newNode's next pointer to where the current head is (basically NULL or the prev node
    head = newNode; // sets the head pointer to the newNode
    printf("Inserted %d at the front.\n", newData);
}

// --- 2. Delete from End ---
void deleteFromEnd() {
    // Case 1: List is empty
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    // Case 2: Only one node in the list
    if (head->next == NULL) { // checks if only one(1) node in list
        int deletedData = head->data;
        /*
         * "Follow the head key to the first locker and look at its next key."
         */
        free(head); // frees the memory
        head = NULL; // resets head initialization to NULL
        printf("Deleted %d from the end (list is now empty).\n", deletedData);
        return;
    }

    // Case 3: Multiple nodes
    struct Node* current = head; // starts at the beginning of the list
    struct Node* prev = NULL;

    // Find the last node (current) and second-to-last node (prev)
    while (current->next != NULL) {
        prev = current; // prev to where the current head is, prev is always one step behind current
        current = current->next; // moves current forward
    } // loop sets current to last & prev to second-last

    int deletedData = current->data; // temp variable to store data of last node

    // Disconnect the last node
    prev->next = NULL; // sets the second-last's next node to NULL, disconnecting last node

    // Free the last node's memory
    free(current); // free last node's memory & data

    printf("Deleted %d from the end.\n", deletedData);
}

// --- Utility: Print the List ---
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

// --- Main Function for Testing ---
int main() {
    printf("--- Initial State ---\n");
    printList();

    // Test Insert at Front
    printf("\n--- Insert Operations ---\n");
    insertAtFront(10);  // List: 10 -> NULL
    insertAtFront(20);  // List: 20 -> 10 -> NULL
    insertAtFront(30);  // List: 30 -> 20 -> 10 -> NULL
    printList();

    // Test Delete from End
    printf("\n--- Delete Operations ---\n");
    deleteFromEnd();    // List: 30 -> 20 -> NULL
    printList();

    deleteFromEnd();    // List: 30 -> NULL
    printList();

    deleteFromEnd();    // List: (Empty) - Testing single node case
    printList();

    deleteFromEnd();    // Testing empty list case

    // Remember to free any remaining allocated memory if the program were more complex
    return 0;
}