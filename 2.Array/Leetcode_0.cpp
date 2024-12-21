// array initializing:-

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n]; // It's a bad practice. In this process memory create in stack in compile time. and we take size of array in runtime. If our given size greater than stack memory then it will give us error.

    int arr[10000]; // it is correct.   
    return 0;
}