/* Given two matrix add them together */

#include <iostream>

using namespace std;

int main() {
    int a[2][2] = {{1, 2}, {3,  4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int c[2][2]; // Sum of matrix

    // Add
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    //  Print
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0; 
}