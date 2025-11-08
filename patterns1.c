//
// Created by PREM on 07-11-2025.
//

#include <stdio.h>

void right_angled_triangle(int rows) {
    printf("Right angled triangle with numbers: \n");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void print_diamond_shape(int size) {
    // upper half
    for (int i = 1; i <= size; i++) {
        for (int space = i; space < size; space++) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("%d", i);
        }
        printf("\n");
    }

    // lower half
    for (int i = size - 1; i >= 1; i--) {
        for (int space = size; space > i; space--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("%d", i);
        }
        printf("\n");
    }
}

int main() {
    right_angled_triangle(5);
    printf("\n");
    print_diamond_shape(4);
}