/* Print the nth term of fibbonacci series */

#include <iostream>

using namespace std;

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n  = 4;
    // Series: 1 1 2 3 5 8 13 ...
    cout << fib(n) << endl;
    return 0;
}