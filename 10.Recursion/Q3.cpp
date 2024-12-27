// Array is sorted or not  and binary search by recursion  :-
// Homework:- Sum of all element;
//            Linear search;


#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector <int> v, int i){
    if(i<=1) return true;
    else if(v[i]>v[i-1]){
        return true && isSorted(v, i-1);
    } else {
        return false;
    }
}

bool binarySearch(vector <int> v, int i, int l, int r){
    if(l>r) return false;
    int mid = l+(r-l)/2;
    if(v[mid]== i) return true;
    else if(v[mid]>i) return binarySearch(v, i, l, (mid-1));
    else binarySearch(v, i, (mid+1),  r);
}

int main(){
    vector <int> v;
    int n;
    cout<<"The size of array:- ";
    cin>>n;
    for(int i = 0; i<n; i++){
        cout<<"Enter the data:-";
        int a;
        cin>>a;
        v.push_back(a);
    }
    if(isSorted(v, n-1)){
        int m;
        cout<<"Enter the search number:-";
        cin>>m;
        if(binarySearch(v,m,0,n-1)) cout<<"Element found";
        else cout<<"Element Not found";
    } else {
        cout<<"Array not sorted";
    }
    return 0;
}