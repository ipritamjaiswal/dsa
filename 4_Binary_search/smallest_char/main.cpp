/*
    Given  an array of sorted characters consisting of lowercase alphabets and a particular target value, say k, task is to find the smallest element in the list that is larger than  k, -1 if no element present
*/ 

#include <iostream>

using namespace std;

char get_smallest_element(char a[], int r, char k);

int main() {
    char a[] = {'a', 'c', 'f', 'g', 'h', 'n', 's', 't', 'v', 'y'};

    char k = 'j'; // Answer is 'n'

    char smallest = get_smallest_element(a, 10, k);

    cout << "The smallest element larger than "  << k << " is " << smallest << endl;

    return 0;
}


char get_smallest_element(char a[], int r, char k) {
    int l = 0;
    char res = '?';

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] < k || a[mid] == k) {
            l = mid + 1;
        }
        else {
            res = a[mid];
            r = mid - 1;
        }
    }

    return res;
}