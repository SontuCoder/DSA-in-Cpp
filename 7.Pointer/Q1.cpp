// 1st example

#include<iostream>
using namespace std;

int main(){

    int num = 5;
    cout<<"Number be:- "<<num<<endl;

    // Address of operator:- &
    cout<<"Address of num is:- "<< &num<<endl;

    // Store Pointer:-
    int *ptr = &num;
    cout<<"value in address:-"<<ptr<<endl;
    cout<<"value in address:-"<<*ptr<<endl;

    // char
    char ch = 'a';
    char *p = &ch;
    cout<<"Value of char:-"<<ch<<endl;
    cout<<"value of pointer:-"<<p<<endl;
    cout<<"value of pointer address:-"<<*p<<endl;

    int m = 1;
    int p1 = m;
    int *n = &m;

    cout<<"m :- "<<m<<endl;
    cout<<"p1 :- "<<p1<<endl;

    (*n)++;

    cout<<"m :- "<<m<<endl;
    cout<<"p1 :- "<<p1<<endl;

    (*n)++;

    cout<<"m :- "<<m<<endl;
    cout<<"p1 :- "<<p1<<endl;

    (*n)++;

    cout<<"m :- "<<m<<endl;
    cout<<"p1 :- "<<p1<<endl;

    return 0;
}