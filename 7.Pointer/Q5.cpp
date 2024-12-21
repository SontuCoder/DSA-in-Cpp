// MCQ :-

#include<iostream>
using namespace std;

int main(){

    // mcq 1:-

    int first = 8;
    int second = 18;
    int *ptr = &second;
    *ptr = 9;
    // cout<<first<<" "<< second<<endl;

    // mcq 2:-

    int a = 6;
    int *p = &a;
    int *q = p;
    (*q)++;
    // cout<< a;

// mcq 3:-
    int arr[] = {11,12,13,14};
    // int *m = *arr++;
    // cout<< *m;

// mcq 4:-
    char ch = 'a';
    char *pr = &ch;
    ch++;
    // cout<<*pr;

// mcq 5:-
    char ar[] = "abba";
    char *g = ar;
    char *h = &ar[0];
    // cout<<g<<endl;
    // cout<<h<<endl;


// mcq 6:- 
    h++;
    cout<<h<<endl;

// more questions in :- https://bit.ly/3Hh9KyZ

    return 0;
}