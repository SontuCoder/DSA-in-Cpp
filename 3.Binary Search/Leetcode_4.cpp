// Search in a rotate array
// IO:- [7,9,1,2,3], 5=> -1; flase
// IO:- [7,9,1,2,3], 2=> 3; true


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

// Binary search in a subarray
int binarySearch(vector<int>& v, int l, int r, int s) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (v[mid] == s) {
            return mid;
        } else if (v[mid] < s) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

// Search for the element in the rotated array
int searchInRotatedArray(vector<int>& v, int s) {
    int pivot = findPivot(v);
    if (v[pivot] <= s && s <= v[v.size() - 1]) {
        // Search in the right half
        return binarySearch(v, pivot, v.size() - 1, s);
    } else {
        // Search in the left half
        return binarySearch(v, 0, pivot - 1, s);
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
    int s;
    cout << "Enter the search number: ";
    cin >> s;
    int result = searchInRotatedArray(a, s);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}
