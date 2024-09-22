#include <iostream>
#include <math.h>

using namespace std;

int binaryToDecimal(int n) {
    int decimal = 0;
    int pow = 1;
    while (n > 0) {
        decimal += n % 10 * pow;
        n /= 10;
        pow *= 2;
    }
    return decimal;
}

int main(void) {
    int n;
    cout << "Enter: ";
    cin >> n;
    cout << binaryToDecimal(n) << endl;
    return 0;
}