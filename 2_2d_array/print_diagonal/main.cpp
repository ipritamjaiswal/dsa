/*
    Given and n * n matrix
    - Print its Principal diagonal elements
    - Print its Secondary diagonal elements
*/

#include <iostream>

using namespace std;

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Printing the principal diagonal elements\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
           if (i == j) {
              cout << a[i][j] << " ";
           }
        }
    }
    cout << endl;

    cout << "Printing the secondary diagonal elements\n";

    int j = 2;
    for (int i = 0; i < 3; i++) {
        cout << a[i][j] << " ";
        j--;
    }
    cout << endl;
    return 0;
}