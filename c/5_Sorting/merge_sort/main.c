#include <stdio.h>

void mergeHalves(int left[], int right[], int array[], int m, int n) {

    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (left[i] < right[j]) {
            array[k] = left[i];
            i++;
        }
        else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy Remaining elements
    while (i < m) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < n) {
        array[k] = right[j];
        j++;
        k++;
    }
    
}

void mergeSort(int array[], int size) {
    if (size <= 1) {
        return;
    }
    
    int mid = size / 2;
    
    int left[mid];
    int right[size - mid];
    for (int i = 0; i < mid; i++) {
        left[i] = array[i];
    }

    for (int i = mid; i < size; i++) {
        right[i - mid] = array[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    mergeHalves(left, right, array, mid, size - mid);
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) {
    int array[] = {3, 1, 5, 4, 2};
    int size = sizeof(array) / sizeof(array[0]);
    mergeSort(array, size);
    printArray(array, size);
    return 0;
}