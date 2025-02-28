// Sort 0,1,2:-


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
    int curr = 0;
    while(curr<=j){
        if (v[curr]==2)
        {
            swap(v[curr],v[j]);
            j--;
        }
        else if (v[curr]==1)
        {
            curr++;
        }
        else{
            swap(v[i],v[curr]);
            i++;
            curr++;
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