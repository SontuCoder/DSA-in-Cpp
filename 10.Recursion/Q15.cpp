// Kth-Bit set or not:-


#include<iostream>
using namespace std;

bool setOrNot(int n, int k){
    if(k == 1){
        if(n%2) return true;
        return false;
    }
    return setOrNot(n/2, k-1);
}

bool setOr(int n, int k){
    int mark = 1;
    mark = mark<<k;
    return n&mark;
}
int main(){
    int n,k;
    cout<<"Enter :- ";
    cin>>n>>k;
    cout<<" Set :-"<<setOr(n,k);
    return 0;
}