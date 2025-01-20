// Implement Lower Bound

#include<iostream>
#include<vector>
using namespace std;

int boundary(vector<int> v, int target){
    int i = 0;
    int j = v.size()-1;
    while(i<j){
        int mid = i + (j-i)/2;
        if(v[mid]<target){
            i = mid+1;
        } else{
            j = mid;
        }
    }
    return j;
}

int main(){
    vector<int> v ={3, 5, 8, 15, 19};
    cout<<"index :- "<<boundary(v,9);
    return 0;
}