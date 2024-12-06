// 231. Power of Two

// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2^x.

// Example 1:
// Input: n = 1
// Output: true
// Explanation: 2^0 = 1

// Example 2:
// Input: n = 16
// Output: true
// Explanation: 2^4 = 16

// Example 3:
// Input: n = 3
// Output: false

#include<iostream>
#include<math.h>
using namespace std;

int main(){
    cout << "Enter the number: ";
    int n;
    cin >> n;
    int j=1;
    for(int i=0; i<=30; i++){
        if(abs(n) == pow(2,i)){
            cout<<"True";
            j=0;
            break;
        }
    } 
    if(j) {
    cout<<"False";
    }
    return 0;
}