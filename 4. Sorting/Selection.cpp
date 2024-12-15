// Selection Sorting :-

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    cout<<"The vector be:- ";
    for(int i:v){
        cout<<i<< " ";
    } cout<<endl;
}

void selctionSort(vector<int> &v){ // takes O(n^2) time, and O(1)
    int i=0;
    while(i<v.size()-1){
        int min = i;
        for(int j = i+1; j<v.size(); j++){
            if(v[j]<v[min])
                min = j;
        }
        swap(v[i],v[min]);
        i++;
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
    selctionSort(v);
    print(v);
    cout<<"==============================="<<endl;
    return 0;
}