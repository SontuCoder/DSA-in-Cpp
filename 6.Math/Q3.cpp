// GCD/ HCF:-

#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(a>b){
        if(a%b==0){
            return b;
        } else {
            gcd(b,a%b);
        }
    } else {
        if(b%a==0){
            return a;
        } else {
            gcd(a, b%a);
        }
    }
}

int gcd2(int a, int b){
    if(a==0)
    return b;
    if(b==0)
    return a;

    while(a != b){
        if(a>b){
            a=a-b;
        } else {
            b=b-a;
        }
    }
    return a;
}


int main(){
    int a;
    int b;
    cout<<"Enter a:-";
    cin>>a;
    cout<<"Enter b:-";
    cin>>b;

    cout<<"The GCD:- "<<gcd2(a,b);
    return 0;
}