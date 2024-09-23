#include <iostream>

using namespace std;

void interSection(int arr1[], int s1, int arr2[], int s2) {
    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s2; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {8, 4, 12, 2, 9, 1};

    interSection(arr1, 5, arr2, 6);
    
    return 0;
}