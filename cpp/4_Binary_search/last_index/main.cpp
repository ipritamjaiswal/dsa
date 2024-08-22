/*Find the last index of element in an array*/

#include <iostream>

using namespace std;

int binarySearch(int a[], int l, int r, int k) {
    int index = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (a[mid] > k) {
            r = mid - 1;
        }
        else if (a[mid] < k) {
            l = mid + 1;
        }
        else  {
            index = mid;
            l = mid + 1;
        }
        
    }
    return index;
}

int main() {
    int a[] = {1, 4, 4, 4, 4, 5, 6, 7, 7, 9};
    int k = 4;
    cout << "Last index of " << k << " is " << binarySearch(a, 0, 9, k) << endl;
    return 0;
}