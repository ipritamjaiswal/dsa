/* Implementation of Binary Search */

#include <iostream>

using namespace std;

int binarySearch(int a[], int l, int r, int k) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] > k) {
            // Search Left
            r = mid - 1;
        }
        else if (a[mid] < k) {
            // Search Right
            l = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int l = 0;
    int r = 8;
    int k = 3;
    cout << "Element 3 is in position " << binarySearch(a, l, r, k) + 1 << endl;
    return 0;
}