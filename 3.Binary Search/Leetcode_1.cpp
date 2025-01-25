// First and Last Position of an Element In Sorted Array 11

// You have been given a sorted array/list ARR consisting of 'N' elements. You are also given an integer 'K'.

// Now, your task is to find the first and last occorrence of 'K' in ARR.

// 1. If 'K' is not present in the array, then the first and the last occurrence will be -1..
// 2. ARR may contain duplicate elements.
// For example, if ARR = [0, 1, 1, 5] and K = 1, then the first and last occurrence of 1 will be 1 and 2.

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

int first(const vector<int>& v, int s) {
    int i = 0, j = v.size() - 1, mid, result = -1;
    while (i <= j) {
        mid = i + (j - i) / 2;
        if (v[mid] == s) {
            result = mid;  // Potential answer
            j = mid - 1;   // Search left half for earlier occurrence
        } else if (v[mid] < s) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return result;
}

int last(const vector<int>& v, int s) {
    int i = 0, j = v.size() - 1, mid, result = -1;
    while (i <= j) {
        mid = i + (j - i) / 2;
        if (v[mid] == s) {
            result = mid;  // Potential answer
            i = mid + 1;   // Search right half for later occurrence
        } else if (v[mid] < s) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return result;
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
    cout << "Enter the number to search: ";
    cin >> s;

    int f = first(a, s);
    int l = last(a, s);

    cout << "The boundaries are: " << f << " " << l << endl;
    return 0;
}
