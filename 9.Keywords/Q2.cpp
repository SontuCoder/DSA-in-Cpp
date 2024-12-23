// Default parameter

#include<iostream>
using namespace std;

int add(int a, int b = 8){
    return a+b;
}

int main(){
    int m = 5;
    int n = 6;
    cout<<add(m,n)<<endl;
    cout<<add(m);
    return 0;
}