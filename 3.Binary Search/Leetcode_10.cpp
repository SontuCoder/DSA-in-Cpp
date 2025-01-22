// Upper bound

#include<iostream>
#include<vector>
using namespace std;

int upperbound(vector<int> v, int target){
    int i = 0;
    int j = v.size();
    while(i<j){
        int mid = i+(j-i)/2;
        if(v[mid]<=target){
            i = mid+1;
        } else {
            j = mid;
        }
    }
    return i;
}

int main(){
    vector<int> v ={3, 5, 8, 9, 15, 19};
    cout<<"index :- "<<upperbound(v,9);
    return 0;
}