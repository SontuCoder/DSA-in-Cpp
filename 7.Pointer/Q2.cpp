// Array and Pointer :-

#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,6,2,4,6};

    cout<<"address of first block:- "<< arr<<endl;
    cout<<"address of first block:- "<< &arr[0]<<endl;

    cout<<"value of first block:- "<< *arr<<endl;
    cout<<"value of first block:- "<< arr[0]<<endl;

    cout<<"value of first block + 1:- "<< *arr+1<<endl;


    cout<<"value of second block:- "<< *(arr+1)<<endl;
    cout<<"value of second block:- "<< arr[0+1]<<endl;

// Formula -> arr[i] = *(arr+i)

    cout<<"value of second block:- "<< 3[arr]<<endl;

// also -> i[arr] = arr[i] = *(arr+1)


//============== Difference ==========//

int li[] = {25,24,1,6,2};
int * p = &li[0]; 

cout<<sizeof(li)<<endl;
cout<<sizeof(p)<<endl;

cout<<*(p+1)<<endl;
cout<<*(li+1)<<endl; 

// ERROR
// li = li+1;

cout<<"Before pointer increment:- "<<p<<endl;
cout<<"Before pointer increment:- "<<*p<<endl;

p = p+1;
cout<<p<<endl;
cout<<*p<<endl;



// ================ pointer with char ==================//

//  cout() print full char

char ch[5] = "abba";
char *c = &ch[0]; // It has highly risk it is not acceptable.

cout<<"Char:- "<< ch <<endl;
cout<<"Char:- "<< c <<endl; // it print upto null charecter.

char temp = 'e';
char *te = &temp;

cout<<"without null:-"<<te<<endl;

    return 0;
}