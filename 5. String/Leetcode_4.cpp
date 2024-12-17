// Palindrom word :-
#include<iostream>
using namespace std;

bool palindrome(char ch[], int n){
    int i = 0;
    int j = n-1;
    while(i<j){
        if(ch[i++] != ch[j--])
            return false;
    }
    return true;
}

int main(){
    char name[10];
    cout<<"Enter the name be:- ";
    cin>>name;
    int n =0;
    while(name[n]!='\0'){
        n++;
    }
    cout<<"The name be Palindrom:- "<<palindrome(name,n);
    return 0;
}