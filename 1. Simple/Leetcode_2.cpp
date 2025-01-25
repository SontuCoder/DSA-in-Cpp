// 191. Number of 1 Bits

// Given a positive integer n, write a function that returns the number of 
// set bits
//  in its binary representation (also known as the Hamming weight).

// Example 1:

// Input: n = 11
// Output: 3
// Explanation:
// The input binary string 1011 has a total of three set bits.

// Example 2:
// Input: n = 128
// Output: 1
// Explanation:
// The input binary string 10000000 has a total of one set bit.


#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the number: ";
    int n;
    cin>>n;
    int count =0;
    while(n!=0){
        int a = n%2;
        n/=2;
        if(a) count++;
    }
    cout<<"The number of 1 bit be:"<<bits(n)<<endl;
    return 0;
}