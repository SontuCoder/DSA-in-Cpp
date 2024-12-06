// sort 0 and 1, 

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

void dupli(vector<int> &v){
    int i=0, j=v.size()-1;

    while(i<j){
        while (v[i]==0 && i<j)
        {
            i++;
        }
        while (v[j]==1 && i<j)
        {
            j--;
        }
        if(i<j){
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
}


int main(){
    vector<int> a;
    int n;
    cout<<"Enter the number the First array numbers:- ";
    cin>>n;
    for(int i = 0;i<n; i++){
        cout<<"Enter the number:- ";
        int j ;
        cin>>j;
        a.push_back(j);
    }
    print(a);

    dupli(a);
    cout<<"The sorted be: ";
    print(a);

    return 0;
}