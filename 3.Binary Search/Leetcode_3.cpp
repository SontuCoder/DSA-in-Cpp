// Find Pivot in a rotate array
// IO:- [7,9,1,2,3] => 1


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

// Function to find the pivot (index of the smallest element)
int findPivot(vector<int>& v) {
    int i = 0, j = v.size() - 1;
    while (i < j) {
        int mid = i + (j - i) / 2;
        if (v[mid] > v[j]) {
            i = mid + 1; 
        } else {
            j = mid; 
        }
    }
    return i; 
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
    cout << "The Privot element index: "<< findPivot(a);
    return 0;
}
