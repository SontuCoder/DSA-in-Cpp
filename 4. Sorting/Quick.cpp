// Quick Sorting :-

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    cout<<"The vector be:- ";
    for(int i:v){
        cout<<i<< " ";
    } cout<<endl;
}

void marge(vector<int> &v, int l, int mid, int r){
    int i = l;
    int j = mid+1;
    vector<int> a;
    while(i<=mid && j<=r){
        if(v[i]<v[j]){
            a.push_back(v[i]);
            i++;
        } else {
            a.push_back(v[j]);
            j++;
        }
    }
    while(i<=mid){
        a.push_back(v[i]);
        i++;
    }
    while(j<=r){
        a.push_back(v[j]);
        j++;
    }
    for (int k = 0; k < a.size(); k++) {
        v[l + k] = a[k];
    }
}

void qiuickSort(vector<int> &v, int l, int r){ // takes O(nlogn) time, and O(n) space.
    if(l<r){
        int mid = l + (r-l)/2;
        margeSort( v, l,mid);
        margeSort(v, mid+1, r);
        marge(v, l, mid, r);
    }
}

int main(){
    int n;
    cout<<"Enter the number of element:- ";
    cin>>n;
    cout<<"==============================="<< endl;
    vector<int> v;
    for(int i=0; i<n; i++){
        int a;
        cout<<"Enter the number:- ";
        cin>>a;
        v.push_back(a);
    }
    cout<<"==============================="<< endl;
    print(v);
    cout<<"==============================="<< endl;
    quickSort(v,0,v.size()-1);
    print(v);
    cout<<"==============================="<<endl;
    return 0;
}