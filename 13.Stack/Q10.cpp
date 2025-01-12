// Next smaller number :-

#include<iostream>
#include<stack>
using namespace std;

void print(int a[], int n){
    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}

void small(int a[], int n){
    stack<int> s;
    s.push(-1);
    for(int i = n-1; i>=0; i--){
        int curr = a[i];
        while(s.top()>= a[i]){
            s.pop();
        }
        a[i] = s.top();
        s.push(curr);
    }
}

int main(){
    int a[] = {2,1,4,3,1};
    print(a, 5);
    small(a, 5);
    print(a, 5);
    return 0;
}