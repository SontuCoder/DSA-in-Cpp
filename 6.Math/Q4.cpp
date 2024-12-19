// Modular Exponetiation:- 

// ( m ^ n ) % y // time takes O(log n) :

#include<iostream>
using namespace std;

int modulo(int m, int n, int y){
    int res = 1;
    while(n>0){
        if(n%2){ // odd
            res = ((res%y) * (m%y))%y;
        }
        m = ((m%y) * (m%y))%y;
        n = n>>1;
    }
    return res;
}

int main(){
    int m;
    int n;
    int y;

    cout<<"Enter the three numbers:-"<<endl;
    cin>>m;
    cin>>n;
    cin>>y;
    cout<<"The ans:- "<<modulo(m,n,y);
    return 0;
}