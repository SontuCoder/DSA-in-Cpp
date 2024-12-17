// Reverse the String :-
#include<iostream>
using namespace std;


void reverse(char ch[], int n){
    int i = 0;
    int j = n-1;
    while(i<j){
        swap(ch[i++], ch[j--]);
    }
}


int main(){
    char name[10];
    cout<<"Enter the name be:- ";
    cin>>name;
    int n =0;
    while(name[n]!='\0'){
        n++;
    }
    reverse(name,n);
    cout<<"The reverse name:- "<<name;
    return 0;
}