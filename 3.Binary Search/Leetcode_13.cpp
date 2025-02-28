// Nth Root of a Number :-

#include<iostream>
#include<math.h>
using namespace std;

int root(int n, int m){
    if(n<0) return -1;
    if(n<=1) return n;
    int l = 1;
    int r = n;
    while(l<=r){
        int mid = l +(r-l)/2;
        if(int(pow(mid,m)) == n){
            return mid;
        } else if(int(pow(mid,m)) > n){
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return -1;
}

int main(){
    int n, m;
    cout<<"Enter number:- ";
    cin>>n>>m;
    cout<< root(n,m);
    return 0;
}

