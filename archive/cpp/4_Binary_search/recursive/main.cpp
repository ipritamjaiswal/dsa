#include <iostream>

using namespace std;

int binarySearch(int a[], int l, int r, int k);

int main() {
    int a[] = {1, 3, 5, 6, 7, 12, 23, 18, 22};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 7; // 4
    int index = binarySearch(a, 0, n - 1, k);

    cout << "Index is " << index << endl;
    return 0;
}

int binarySearch(int a[], int l, int r, int k) {
    if (l > r) {
        return -1;
    }

    int mid = l + (r - l)/ 2;

    if (a[mid] > k) {
        // Search Left
        return binarySearch(a, l, mid - 1, k);
    }
    else if (a[mid] < k)  {
        // Search Right
        return binarySearch(a, mid + 1, r, k);
    }
    else {
        return mid;
    }
}