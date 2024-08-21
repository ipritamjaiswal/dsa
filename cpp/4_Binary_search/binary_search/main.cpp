/* Implementation of Binary Search */

#include <iostream>

using namespace std;

int binarySearch(int array[], int size, int k) {
    int s = 0;
    int e = size - 1;

    while (s <= e) {
        // Compute mid
        int mid = (s + e) / 2;
        // Go right
        if (array[mid] < k) {
            s = mid + 1;
        }
        // Go left
        else if (array[mid] > k) {
            e = mid - 1;
        }
        // Element fount
        else {
            return mid;
        }
    }

    return -1;
}

int main(void) {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Element 3 is in position " << binarySearch(array, 9, 3) + 1 << endl;
    return 0;
}