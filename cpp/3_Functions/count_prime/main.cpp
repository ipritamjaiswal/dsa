/*Count the number of Primes in an array*/

#include <iostream>

using namespace std;

// Function Prototypes
int is_prime(int);
int count_prime(int arr[], int size);

int main(void) {
    int a[] = {2, 3, 4, 5, 13, 17, 28, 29}; // Answer is 6
    int size = sizeof(a) / sizeof(a[0]);

    cout << "The total number of prime is " << count_prime(a, size) << endl;

    return 0;
}

// Function definitions
int is_prime(int n) {
    if (n <= 0) {
        return 0;
    }

    if (n == 1 || n == 2) {
        return 1;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int count_prime(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (is_prime(arr[i])) {
            count++;
        }
    }
    return count;
}