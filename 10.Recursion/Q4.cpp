// reverse of a string using recursion
// palindrom 

#include<iostream>
using namespace std;

void reverseString(string& str, int l, int r){
    if(r<l) return;
    swap(str[l],str[r]);
    return reverseString(str, l+1, r-1);
}

int main(){
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    reverseString(str, 0, str.length()-1);
    cout<<"reverse of it: "<<str;
    return 0;
}