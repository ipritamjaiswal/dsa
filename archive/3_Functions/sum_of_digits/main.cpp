/* Function to get the sum of digits */

#include <iostream>

using namespace std;

int sum_of_digits(int);

int main(void) {
    int num;
    cout << "Enter: ";
    cin >> num;

    cout << "Sum of digits is " << sum_of_digits(num) << endl;
    return 0;
}

int sum_of_digits(int num) {
    int sum = 0;
    while (num >= 1) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}