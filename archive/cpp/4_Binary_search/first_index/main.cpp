/*Find the index of first occurance of element in the array*/

#include <iostream>

using namespace std;

int binarySearch(int a[], int l, int r, int k) {
    int res = -1;
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
            res = mid;
            r = mid - 1;
        }
    }

    return res;
}

int main() {
    int a[] = {1, 4, 4, 4, 4, 5, 6, 7, 7, 9};
    int k = 7;
    cout << "First index of " << k << " is " << binarySearch(a, 0, 9, k) << endl;
    return 0;
}