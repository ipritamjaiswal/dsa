// Program to reverse an array of integers

#include <iostream>

using namespace std;

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5];
    int j = 0;

    for (int i = 4; i >= 0; i--) {
        b[j] = a[i];
        j++;
    }

    for (int i = 0; i < 4; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}