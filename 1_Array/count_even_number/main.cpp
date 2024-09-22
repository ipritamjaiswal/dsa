// Program to count the even numbers in a list of numbers

#include <iostream>

using namespace std;

int main(void) {
    int array[10] = {2, 1, 4, 5, 6, 7, 8, 9, 10, 11};
    int count = 0;

    for (int i = 0; i < 10; i++) {
        if (array[i] % 2 == 0) {
            count++;
        }
    }

    cout << "The number of even numbers in the array is: " << count << endl;

    return 0;
}