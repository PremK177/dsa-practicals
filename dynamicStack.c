#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node Structure
// Each node contains the data and a pointer to the next node.
struct Node {
    int data;
    struct Node* next;
};

// Global pointer for the top of the stack
struct Node* top = NULL; 

/**
 * @brief Creates a new node with the given data.
 * @param data The integer value to store in the node.
 * @return A pointer to the newly created node.
 */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        // Handle memory allocation failure
        printf("Error: Memory allocation failed!\n");
        exit(1); 
    }
    newNode->data = data; //assigning data
    newNode->next = NULL; //assigning the 'next' pointer as NULL
    return newNode;
}

// --- PUSH OPERATION ---
/**
 * @brief Adds an element to the top of the stack.
 * This is equivalent to insertion at the beginning of the linked list.
 * @param data The value to push onto the stack.
 */
void push(int data) {
    // 1. Create the new node
    struct Node* newNode = createNode(data); 

    // 2. Link the new node to the current top
    newNode->next = top;
    // In stack, the 'next' points downward, to the older element

    // 3. Update the top pointer
    top = newNode; 

    printf("Pushed: %d\n", data);
}

// --- POP OPERATION ---
/**
 * @brief Removes and returns the element from the top of the stack.
 * This is equivalent to deletion from the beginning of the linked list.
 * @return The value popped from the stack, or -1 for underflow (can be modified).
 */
int pop() {
    if (top == NULL) {
        printf("Error: Stack Underflow! Cannot pop.\n");
        return -1; // Indicate error/failure
    }

    // 1. Store the node to be deleted (current top)
    struct Node* temp = top; 
    
    // 2. Store the data to be returned
    int poppedData = temp->data; 
    
    // 3. Move the top pointer to the next node
    top = top->next; 
    
    // 4. Free the memory of the old top node
    free(temp); 
    
    printf("Popped: %d\n", poppedData);
    return poppedData;
}

// --- DISPLAY OPERATION ---
/**
 * @brief Prints all elements of the stack from top to bottom.
 */
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    
    struct Node* current = top;
    printf("\n--- Stack (Top -> Bottom) ---\n");
    
    // Traverse the linked list starting from the top
    while (current != NULL) {
        printf("| %d |\n", current->data);
        current = current->next;
    }
    printf("-------------\n");
}


// --- MAIN FUNCTION (Driver Code) ---
int main() {
    printf("Linked List based Dynamic Stack Demonstration.\n");

    // Push operations
    push(10);
    push(20);
    push(30);
    
    // Display the stack
    display(); // Should display 30, 20, 10
    
    // Pop operation (removes 30)
    pop(); 
    
    // Push another element
    push(40); // 40 is the new top
    
    // Display the updated stack
    display(); // Should display 40, 20, 10
    
    // Pop the remaining elements
    pop(); // Removes 40
    pop(); // Removes 20
    pop(); // Removes 10
    
    // Attempting to pop from an empty stack (Underflow check)
    pop(); 
    
    // Clean up: display empty stack
    display(); 

    return 0;
}