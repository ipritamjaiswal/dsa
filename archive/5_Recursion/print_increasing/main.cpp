/* Print num in increasing order */

#include <iostream>

using namespace std;

void printIncreasing(int m, int n) {
    if (n == 0) {
        return;
    }
    
    cout << m - (n - 1) << " ";
    
    printIncreasing(m, n - 1);
}

int main() {
    printIncreasing(5, 5);
    cout << endl;
    return 0;
}