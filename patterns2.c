//
// Created by PREM on 08-11-2025.
//

#include <stdio.h>

void pyramid_with_asterisks(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int space = rows - i; space > 0; space--) {
            printf("  ");
        }
        for (int j = 1; j <= 2*i-1; j++) {
            printf(" *");
        }
        printf("\n");
    }
}

void pyramid_with_alphabets(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int space = rows - i; space > 0; space--) {
            printf("  ");
        }
        char ch = 'A';
        for (int j = 1; j <= 2*i-1; j++) {
            printf(" %c", ch);
            ch++;
        }
        printf("\n");
    }
}

int main() {
    pyramid_with_asterisks(5);
    printf("\n");
    pyramid_with_alphabets(5);
}
