/*
    Given an array of N integers, and a number of value, the task is to find the number of pairs of integers in the arrary whose sum is equal to given value.
*/

#include <iostream>

using namespace std;

int main(void) {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int value = 10;
    int count = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (array[i] + array[j] == value) {
                count++;
            }
        }
    }

    cout << "The number of pairs is " << count << endl;

    return 0;
}