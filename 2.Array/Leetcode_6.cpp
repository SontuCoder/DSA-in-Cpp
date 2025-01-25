// Pair sum , return the pairs;

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<int> v){
    cout<<"The array:- ";
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}

vector<vector<int>> dupli(vector<int> v, int sum){
    int i=0, j=v.size()-1;
    sort(v.begin(),v.end());
    vector<vector<int>> v1;
    while(i<j){
        if(v[i]+v[j]==sum){
            vector<int> b;
            b.push_back(v[i]);
            b.push_back(v[j]);
            v1.push_back(b);
            b.clear();
            i++;
            j--;
        } else if(v[i]+v[j]>sum){
            j--;
        } else {
            i++;
        }
    }
    return v1;
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
    int s;
    cout<<"Enter the sum:- ";
    cin>>s;

    vector<vector<int>> v = dupli(a,s);
    cout<<"The pairs be: ";
    for(vector<int> i:v){

        cout<<i[0]<<" "<<i[1];
        cout<<endl;
    }
    return 0;
}