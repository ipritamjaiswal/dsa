#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<char> st;
    string s = "abc";

    for (char c: s) {
        st.push(c);
    }

    int n = s.length();

    for (int i = 0; i < n; i++) {
        s[i] = st.top();
        st.pop();
    }

    // Print reverse string
    cout << "The reverse string: " << s << endl;
    return 0;
}