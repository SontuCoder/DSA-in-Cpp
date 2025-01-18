// Longest Subarray with given Sum K(Positives)



#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// use only for +ve
int longest(vector<int> v, int k){
    int maxilen =0;
    int l = 0;
    int sum = 0;
    for(int i =0; i<v.size(); i++){
        sum+=v[i];
        while(sum>k){
            sum-=v[l];
            l++;
        }
        if(sum == k){
            maxilen = max(maxilen,i-l+1);
        }
    }
    return maxilen;
}

// for all -ve and +ve
int longest2(vector<int> v, int k){
    int maxlen = 0;
    unordered_map<int, int> m;
    int prePixSum = 0;
    for(int i = 0; i<v.size(); i++){
        prePixSum += v[i];
        if(prePixSum ==k){
            maxlen = i+1;
        }
        if(m.find(prePixSum-k) != m.end()){
            maxlen = max(maxlen, i-m[prePixSum-k]);
        }
        if(m.find(prePixSum) == m.end()){
            m[prePixSum] = i;
        }
    }
    return maxlen;
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
    cout<<"Longest subarray :- "<<longest2(v,3);
    return 0;
}