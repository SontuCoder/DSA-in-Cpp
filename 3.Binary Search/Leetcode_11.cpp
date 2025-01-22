// Search Insert Position

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

int insert(vector<int> &v, int n){
    int i = 0;
    int j = v.size();
    while(i<j){
        int mid = i+(j-i)/2;
        if(v[mid]>n){
            j = mid;
        } else if(v[mid] == n){
            return mid;
        } else {
            i = mid+1;
        }
    }
    return i;
}

int main(){
    vector<int> v = {1,2,4,7};
    print(v);
    cout<<"Position:- "<<insert(v,2);
    return 0;
}