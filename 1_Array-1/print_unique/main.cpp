#include <iostream>

using namespace std;

void print_unique(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        
        bool unique = true;
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                unique = false;
                break;
            }
        }

        if (unique) {
            cout << arr[i] << " ";
        }  
    }

    cout << endl;
}

int main() {
    int arr[] = {1, 1, 2, 3, 4, 3, 5, 6, 4, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    print_unique(arr, size);
    
    return 0;
}