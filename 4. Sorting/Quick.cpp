// Quick Sorting :-

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    cout<<"The vector be:- ";
    for(int i:v){
        cout<<i<< " ";
    } cout<<endl;
}

int partition(vector<int> &v, int l, int r) {
    int pivot = v[l];
    int i = l + 1;
    int j = r;
    while (i <= j) {
        while (i <= r && v[i] <= pivot) {
            i++;
        }
        while (j >= l && v[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(v[i], v[j]);
        }
    }
    swap(v[l], v[j]);
    return j;
}


void quickSort(vector<int> &v, int l, int r){ // takes O(nlogn) time, and O(n) space.
    if(l>=r) return;
        int m = partition( v, l,r);
        quickSort(v, m+1, r);
        quickSort(v, l, m-1);
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
    quickSort(v,0,v.size()-1);
    print(v);
    cout<<"==============================="<<endl;
    return 0;
}