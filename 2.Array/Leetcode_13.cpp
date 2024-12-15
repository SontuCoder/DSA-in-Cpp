// Add the array:-
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
    cout<<"The array be:- ";
    for(int i :v){
        cout<<i<<" ";
    }
    cout<<endl;
}

vector<int> add(vector<int> &v, vector<int> &v1){
    int carry = 0;
    vector<int> v2;
    int i = 0;
    int n = v.size();
    int n1 = v1.size();

    while(i<n && i<n1){
        int sum = carry+v[n-i-1]+v1[n1-i-1];
        carry = sum/10;
        v2.insert(v2.begin(),sum%10);
        i++;
    }
    while(i<n){
        int sum = carry+v[n-i-1];
        carry = sum/10;
        v2.insert(v2.begin(),sum%10);
        i++;
    }
        while(i<n1){
        int sum = carry+v1[n1-i-1];
        carry = sum/10;
        v2.insert(v2.begin(),sum%10);
        i++;
    }
    if(carry!=0){
        v2.insert(v2.begin(),carry);
    }
    return v2;
}

vector<int> add2(const vector<int>& v, const vector<int>& v1) {
    int carry = 0;
    vector<int> v2;
    int n = v.size();
    int n1 = v1.size();
    int i = 0;

    while (i < n || i < n1 || carry != 0) {
        int digit1 = (i < n) ? v[n - i - 1] : 0; 
        int digit2 = (i < n1) ? v1[n1 - i - 1] : 0; 
        int sum = carry + digit1 + digit2;

        carry = sum / 10; 
        v2.insert(v2.begin(), sum % 10);
        i++;
    }

    return v2;
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
    cout<<"Enter the number of element:- ";
    cin>>n;
    cout<<"==============================="<< endl;
    vector<int> v1;
    for(int i=0; i<n; i++){
        int a;
        cout<<"Enter the number:- ";
        cin>>a;
        v1.push_back(a);
    }
    cout<<"==============================="<< endl;
    print(v);
    print(v1);
    cout<<"==============================="<< endl;
    cout<<"The sum of two array:- "<<endl;
    print(add(v,v1));
    cout<<"==============================="<<endl;
    return 0;
}