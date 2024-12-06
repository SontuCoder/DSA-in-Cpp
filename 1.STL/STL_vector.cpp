#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v;
    cout << "Capacity of vector: " << v.capacity() << endl;

    v.push_back(2);
    cout << "Capacity of vector: " << v.capacity() << endl;

    v.push_back(4);
    cout << "Capacity of vector: " << v.capacity() << endl;

    v.push_back(3);
    cout << "Capacity of vector: " << v.capacity() << endl;

    v.push_back(5);
    cout << "Capacity of vector: " << v.capacity() << endl;

    v.push_back(1);
    cout << "Capacity of vector: " << v.capacity() << endl;

    cout << "Size of vector: " << v.size() << endl; // Size is not Capacity. size <= capacity.
    cout << "Element at index 2: " << v.at(2) << endl;
    cout << "Element at index 2: " << v[2] << endl;

    cout << "First element of vector: " << v.front() << endl;
    cout << "Last element of vector: " << v.back() << endl;

    cout << "All Elements in v: ";
    print(v);

    v.pop_back();
    cout << "All Elements in v After pop: ";
    print(v);

    v.clear();
    cout << "Capacity of vector: " << v.capacity() << endl;
    cout << "Size of vector: " << v.size() << endl;

    vector<int> v2 = {6, 1, 5, 9, 6, 8};
    v2.resize(3);
    cout << "All Elements in v2: ";
    print(v2);

    v2.resize(5);
    cout << "All Elements in v2: ";
    print(v2);

    v2.resize(10, 5);
    cout << "All Elements in v2: ";
    print(v2);

    // Demonstrating insertion
    v2.insert(v2.begin() + 2, 99); // Inserts 99 at index 2
    cout << "After inserting 99 at index 2: ";
    print(v2);

    cout << "After remove at index 3: ";
    v2.erase(v2.begin()+3);
    print(v2);

    v.swap(v2);
    cout << "After Swap v, v2: ";
    print(v);
    print(v2);
    return 0;
}
