/* Given a sorted integer array containing duplicates, count occurance of a given number */

#include <iostream>

using namespace std;

int first_occurance(int a[], int r, int k) {
    int l = 0;
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

int last_occurance(int a[], int r, int k) {
    int l = 0;
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

int frequency(int a[], int r, int k) {
    int f = first_occurance(a, r, k);
    int l = last_occurance(a, r, k);
    if (f == -1 && l == -1) {
        return 0;
    }
    return l - f + 1;
}

int main(void) {
    int a[] = {1, 3, 4, 4, 4, 5, 7, 7, 9};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;

    int freq = frequency(a, n - 1, k);

    cout << "The frequency of " << k << " is " << freq << endl;
    return 0;
}
