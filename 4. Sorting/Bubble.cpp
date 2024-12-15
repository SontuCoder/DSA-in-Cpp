// Bubble Sorting :-

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    cout<<"The vector be:- ";
    for(int i:v){
        cout<<i<< " ";
    } cout<<endl;
}

void bubbleSort(vector<int> &v){ // takes O(n^2) time, and O(1) space
    for(int i = 0; i<v.size()-1; i++){
        for(int j = 0; j<v.size()-i-1; j++){
            if(v[j]>v[j+1])
                swap(v[j], v[j+1]);
        }
    }
}


void adBubbleSort(vector<int> &v){ // takes O(n^2) time in Worse case(Reverse), O(n) time in Best case, and O(1) space
    bool a = false;
    for(int i = 0; i<v.size()-1; i++){
        for(int j = 0; j<v.size()-i-1; j++){
            if(v[j]>v[j+1])
                swap(v[j], v[j+1]);
                a= true;
        }
        if(!a){
            cout<<"Already sorted"<<endl;
            break;
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
    bubbleSort(v);
    print(v);
    cout<<"==============================="<<endl;
    return 0;
}