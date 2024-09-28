#include <iostream>

using namespace std;

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int maxSum = arr[0];

    for (int st = 0; st < n; st++) {
        int currSum = 0;
        for (int end = st; end < n; end++) {
            currSum += arr[end];
            maxSum = max(maxSum, currSum);
        }
        if (currSum < 0) {
            currSum = 0;
        }
    }

    cout << maxSum << endl;
    
    return 0;
}