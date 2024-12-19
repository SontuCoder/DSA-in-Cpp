// Prime Number:-

#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n<=1){
        return false; 
    } else {
        int a=2;
        while(a<n){
            if(n%a==0){
                return false;
            }
            a++;
        }
        return true;
    }
}

int main(){
    int n;
    cout<<"Enter the number:-";
    cin>>n;
    cout<<"The number be prime or not:- "<<isPrime(n);
    return 0;
}