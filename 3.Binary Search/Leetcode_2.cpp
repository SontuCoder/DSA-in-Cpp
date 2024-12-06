// Peak index of a Mountain Array: leetcode- 852

#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& v) {
    cout << "The array: ";
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int peak(vector<int>& v) {
    int i = 0, j = v.size() - 1,mid;
    while (i <= j) {
        mid = i + (j - i) / 2;
        if (v[mid]> v[mid+1] && v[mid-1]<v[mid]) {
            return mid;
        } else if (v[mid] < v[mid+1] && v[mid-1]<v[mid]) {
            i = mid+1;
        } else if(v[mid] > v[mid+1] && v[mid-1]>v[mid])  {
            j = mid-1;
        }
    }
}


int main() {
    vector<int> a;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter the number: ";
        int j;
        cin >> j;
        a.push_back(j);
    }
    print(a);
    cout << "The Mountain element index: "<< peak(a);
    return 0;
}
