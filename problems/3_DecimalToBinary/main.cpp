#include <iostream>

using namespace std;

int decimalToBinary(int n) {
    int binary = 0;
    int pow = 1;
    while (n > 0) {
        binary += n % 2 * pow;
        n /= 2;
        pow *= 10;
    }
    
    return binary;
}

int main(void) {
    int n;
    cout << "Enter: ";
    cin >> n;
    cout << decimalToBinary(n) << endl;
    return 0;
}