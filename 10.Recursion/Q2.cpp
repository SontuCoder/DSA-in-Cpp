// Fibonacci number (leetcode-509)
// climb stairs (for small number)

// Say digits
#include<iostream>
#include<vector>
using namespace std;

void say(string arr[], vector <string> &v, int n){
    if(n==0){
        return;
    }
    int digit = n%10;
    say(arr,v, n/10);
    v.push_back(arr[digit]);
}

int main(){
    string arr[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};

    int n;
    cout<<"Enter the number:- ";
    cin>>n;
    vector <string> v;
    if(n==0){
        v.push_back(arr[n]);
    } else {
        say(arr, v, n);
    }
    for(string s:v){
        cout<<s<<" ";
    }
    return 0;
}
