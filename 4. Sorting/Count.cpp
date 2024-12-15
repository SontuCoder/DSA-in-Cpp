// Count Sorting :-

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<int> v){
    cout<<"The vector be:- ";
    for(int i:v){
        cout<<i<< " ";
    } cout<<endl;
}

void countSort(vector<int> &v){ // takes O(n+k) time, and O(k) space.
    int maxElemnt = *std::max_element(v.begin(), v.end());
    vector<int> a(maxElemnt+1,0);
    for(int i :v){
        a[i]++;
    }
    // v.clear();
    int m = 0;
    for(int j =0 ; j<a.size(); j++){
        while(a[j]>0){
            v[m++]=j;
            a[j]--;
        }
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
    countSort(v);
    print(v);
    cout<<"==============================="<<endl;
    return 0;
}