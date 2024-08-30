#include <stdio.h>
#include <stdlib.h>

void rotate_array(int a[], int start, int end) {
    // Keep the last element
    int last = a[end];

    // Shift all elements by 1 step
    for (int i = start; i < end; i++) {
        int temp = a[i + 1];
        a[i + 1] = a[i];
        a[i] = last;
        last = temp;
    }
}

void insertion_sort(int a[], int n) {
    if (n <= 2) {
        return;
    }

    for (int i = 1; i < n; i++) {
        // Place elements to right position
        for (int j = 0; j < i; j++) {
            if (a[j] >= a[i]) {
                // Shift elements: Perform rotation by 1 step
                rotate_array(a, j, i);
            }
        }
    }
}

int main() {
    int a[] = {2, 4, 1, 3, 2, 5, 5, 8};

    insertion_sort(a, 8);

    for (int i = 0; i < 8; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}