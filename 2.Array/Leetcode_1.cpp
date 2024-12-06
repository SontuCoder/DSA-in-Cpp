// Swap alternate elements.
// IO:- [1,2,3,4,5,6,7] =>[2,1,4,3,6,5,7]

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    cout<<"The array:- ";
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> a;
    int n;
    cout<<"Enter the number the numbers:- ";
    cin>>n;
    for(int i = 0;i<n; i++){
        cout<<"Enter the number:- ";
        int j ;
        cin>>j;
        a.push_back(j);
    }
    print(a);
    for(int i = 0; i<n-1; i+=2){
        swap(a.at(i), a.at(i+1));
    }
    print(a);
    return 0;
}