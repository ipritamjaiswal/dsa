/*
    Given  an array of sorted characters consisting of lowercase alphabets and a particular target value, say k, task is to find the smallest element in the list that is larger than  k, -1 if no element present
*/ 

#include <iostream>

using namespace std;

char get_smallest_element(char a[], int n, int k);

int main() {
    char a[] = {'a', 'c', 'f', 'g', 'h', 'n', 's', 't', 'v', 'z'};

    char k = 'j'; // Answer is 'n'

    char smallest = get_smallest_element(a, 10, k);

    cout << "The smallest element larger than "  << k << " is " << smallest << endl;

    return 0;
}


char get_smallest_element(char a[], int n, int k) {
    
}