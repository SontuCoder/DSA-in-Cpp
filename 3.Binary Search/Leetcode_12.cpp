// Floor and Ceil in Sorted Array

#include<iostream>
#include<vector>
using namespace std;

void print(const vector<int>& v) {
    cout << "The array: ";
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

pair<int,int> insert(vector<int> &v, int n){
    int i = 0;
    int j = v.size();
    int floor = -1, ceil = -1;
    while(i<=j){
        int mid = i+(j-i)/2;
        if(v[mid]<n){
            i = mid+1;
            floor = v[mid];
        } else if(v[mid]== n){
            return {v[mid],v[mid]};
        } else {
            ceil = v[mid];
            j=mid-1;
        }
    }
    return {floor, ceil};
}

int main(){
    vector<int> v = {1,2,4,7};
    print(v);
    pair<int,int> ans = insert(v,6);
    cout<<"Position:- "<<ans.first<<" "<<ans.second;
    return 0;
}