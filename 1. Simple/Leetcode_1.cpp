// 1281. Subtract the Product and Sum of Digits of an Integer

// Given an integer number n, return the difference between the product of its digits and the sum of its digits.

// Example 1:
// Input: n = 234
// Output: 15 
// Explanation: 
// Product of digits = 2 * 3 * 4 = 24 
// Sum of digits = 2 + 3 + 4 = 9 
// Result = 24 - 9 = 15

#include<iostream>
using namespace std;

int main(){
    cout<<"Enter the number: ";
    int n;
    cin>>n;
    int pro =1;
    int sum =0;
    while(n!=0){
        int a = n%10;
        n/=10;
        sum+=a;
        pro*=a;
    }
    cout<<"the difference be: "<<(pro-sum)<<endl;
    return 0;
}