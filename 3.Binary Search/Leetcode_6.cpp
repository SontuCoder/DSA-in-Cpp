
// Squer root of any element (floating part): 
// 25 => 5

#include <iostream>
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

double root(int s){
    int rootInt = binarySearch(s);

    double f = 1;
    double ans = rootInt;
    for(int i =0; i<3; i++){
        f=f/10;
        for(double j=ans; j*j<s; j= j+f){
            ans = j;
        }
    }
    return ans;
}


int main() {
    int s;
    cout << "Enter the number: ";
    cin >> s;
    double result = root(s);
    cout << "Element found at index: " << result << endl;
    return 0;
}
