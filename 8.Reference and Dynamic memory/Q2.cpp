// Dynamic memory
// when we use stack it's called static allocation.
// and we use heap then it's called dynamic allocation.

#include<iostream>
using namespace std;

int getSum(int *arr, int n){
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    int n;
    cout<<"The size :-";
    cin>>n;

    int *a = new int[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<getSum(a,n);
    delete a; // free heap 

    return 0;
}