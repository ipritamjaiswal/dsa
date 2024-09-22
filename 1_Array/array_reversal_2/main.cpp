/* Reverse the same array without using extra space */

#include <iostream>

using namespace std;

void reverseArray(int array[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        swap(array[start], array[end]);
        start++;
        end--;
    }
}

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};

    reverseArray(a, 5);
    
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    
    cout << endl;
    return 0;
}