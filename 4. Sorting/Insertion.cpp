// Insertion Sorting :-

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    cout<<"The vector be:- ";
    for(int i:v){
        cout<<i<< " ";
    } cout<<endl;
}

void insertionSort(vector<int> &v){ // takes O(n^2) time,Best Case O(n) and O(1) space.
    for(int i = 1; i<v.size(); i++){
        int a = v[i];
        int j = i-1;
        while(j >= 0 && a<v[j]){
            v[j+1] = v[j];
            j--;
        }
        v[j+1]=a;
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
    insertionSort(v);
    print(v);
    cout<<"==============================="<<endl;
    return 0;
}