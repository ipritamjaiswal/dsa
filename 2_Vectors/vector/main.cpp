#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec1;
    vector<int> vec2 =  {1,  2, 3};
    vector<int> vec3(3, 0);

    vec2.push_back(4);
    vec2.push_back(5);
    vec2.pop_back();

    for (int val : vec2) {
        cout << val << endl;
    }

    cout << "Size: " << vec2.size() << endl;
    cout << "Capacity: " << vec2.capacity() << endl;

    cout << vec2.at(0) << endl;
    cout << vec2.front() << endl;
    cout << vec2.back() << endl;

    
    return 0;
}