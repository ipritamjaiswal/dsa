/* Bubble Sort Implementation in C */

#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int a[], int n);

int main(void) {
    int a[] = {4, 2, 5, 3, 1};
    int n = 5;

    bubbleSort(a, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

// Bubble Sort
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap elements
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}