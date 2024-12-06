// 7. Reverse Integer

// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

// Example 1:

// Input: x = 123
// Output: 321

// Example 2:

// Input: x = -123
// Output: -321

// Example 3:

// Input: x = 120
// Output: 21

#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the number: ";
    int n;
    cin>>n;
    int x=n;
    int reverse = 0;
    if(x<0) x=0-x;
    while(x!=0){
        reverse= reverse*10+(x%10);
        x/=10;
    }
    if(n<0) {
        cout<<"Reverse be: "<<-reverse<<endl;
    } else {
        cout<<"Reverse be: "<<reverse<<endl;
    }
    return 0;
}