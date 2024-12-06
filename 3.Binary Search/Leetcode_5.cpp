// Leetcode 69:-
// Squer root of any element: 
// 25 => 5

#include <iostream>
#include<math.h>
using namespace std;


// Binary search in a subarray
int binarySearch(int s) {
    if (s < 2) {
        return s;
    }

    int l = 1, r = s / 2, mid, result;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (mid * mid == s) {
            return mid;
        } else if (mid * mid < s) { 
            l = mid + 1;
            result=mid;
        } else {
            r = mid - 1;
        }
    }
    return result;
}


int main() {
    int s;
    cout << "Enter the number: ";
    cin >> s;
    int result = binarySearch(s);
    cout << "Element found at index: " << result << endl;
    return 0;
}
