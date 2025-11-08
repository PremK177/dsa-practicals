//
// Created by PREM on 08-11-2025.
//

#include <stdio.h>
#include <string.h>

int binary_search(char contacts[][50], int n, char target[]) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int result = strcmp(contacts[mid], target);

        if (result == 0)
            return mid; // found
        else if (result < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // not found
}

int main() {
    int n;
    printf("Enter number of contacts: ");
    scanf("%d", &n);

    char contacts[n][50];
    printf("Enter %d contact names (in sorted order):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", contacts[i]);
    }

    char target[50];
    printf("Enter name to search: ");
    scanf("%s", target);

    int index = binary_search(contacts, n, target);

    if (index != -1)
        printf("Contact '%s' found at position %d.\n", target, index + 1);
    else
        printf("Contact '%s' not found.\n", target);

    return 0;
}
