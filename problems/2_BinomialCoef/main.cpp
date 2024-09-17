#include <iostream>

using namespace std;

int factorial(int n) {
    if (n <= 0) {
        return 0;
    }
    
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n;
    int r;
    cout << "--Find the Binomial Coefficient--" << endl;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter r: ";
    cin >> r;

    int ans = nCr(n, r);
    cout << "Binomail Coefficient of C(" << n << ", " << r << ") is: " << ans << endl;
}