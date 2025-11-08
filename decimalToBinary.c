//
// Created by PREM on 09-11-2025.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 50
int stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

void decimalToBinary(int decimal) {
    int remainder;
    int temp = decimal;
    while (temp > 0) {
        remainder = temp % 2;
        push(remainder);
        temp /= 2;
    }
    printf("Binary equivalent of %d: ", decimal);
    while (!isEmpty()) {
        printf("%d", pop());
    }
    printf("\n");
}

int main() {
    int decimal;

    printf("Enter decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    return 0;
}