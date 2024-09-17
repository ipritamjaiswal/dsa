#include <iostream>

using namespace std;

// Print half triangle
void print_triangle_half(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void print_triangle_half(int n, char c) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << c << " ";
        }
        cout << endl;
    }
}

void print_floyd_triangle(int n) {
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << k << " ";
            k++;
        }
        cout << endl;
    }
}

void print_inverted_triangle(int n) {
    for (int i = 0; i < n; i++) {
        // Print space
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        for (int j = n - i; j > 0; j--) {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

void print_pyramid(int n) {
    for (int i = 0; i < n; i++) {
        // Print n - 1 space
        for (int j = n - 1 - i; j > 0; j--) {
            cout << "  ";
        }
        // Print increasing seq
        for (int j = 0; j <= i; j++) {
            cout << j + 1 << " ";
        }
        // Print decreasing seq
        for (int j = i; j > 0; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print_hollow_diamond(int n, char c) {
    int s = 1;
    // Print upper half
    for (int i = 0; i < n; i++) {
        // Print space before the character
        for (int j = n - i - 1; j > 0; j--) {
            cout << "  ";
        }
        // Print the character
        cout << c << " ";
        // Print space after the character
        if (i > 0) {
            for (int j = 0; j < s; j++) {
                cout << "  ";
            }
            s+=2;
        }
        // Print the character from 2nd line
        (i > 0) ? cout << c << endl : cout << endl;
    }

    s = s - 4;
    // Print lower half
    for (int i = 0; i < n - 1; i++) {
        // Print space before the character
        for (int j = 0; j < i + 1; j++) {
            cout << "  ";
        }
        // Print the character
        cout << c << " ";
        // Print space after the character
        for (int j = 0; j < s; j++) {
            cout << "  ";
        }
        s -= 2;
        // Print the character
        (i < n - 2) ? cout << c << endl : cout << endl;
    }
    
}

int main(void) {
    int n = 10;
    print_triangle_half(n);
    print_triangle_half(n, '*');
    print_floyd_triangle(n);
    print_inverted_triangle(n);
    print_pyramid(n);
    print_hollow_diamond(n, '*');
    return 0;
}