//
// Created by PREM on 08-11-2025.
//

#include <stdio.h>

void bubbleSort(int array[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int array[], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        int min_index = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}

void displayArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter number of items in store: ");
    scanf("%d", &size);

    int prices[size];
    printf("Enter product prices:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &prices[i]);
    }

    int choice;
    printf("\nChoose sorting method:\n1. Bubble Sort\n2. Selection Sort\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        bubbleSort(prices, size);
        printf("\nPrices sorted using Bubble Sort:\n");
    } else if (choice == 2) {
        selectionSort(prices, size);
        printf("\nPrices sorted using Selection Sort:\n");
    } else {
        printf("Invalid choice.\n");
        return 0;
    }

    displayArray(prices, size);

    return 0;
}