// Leaders in an Array
// Problem Statement: Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

// Input:
//  arr = [10, 22, 12, 3, 0, 6]
// Output:
//  22 12 6

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int> v)
{
    cout << "Elements :- ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> lead(vector<int> v){
    vector<int> ans;
    ans.push_back(v[v.size()-1]);
    int maxi = v[v.size()-1];
    for(int i = v.size()-2; i>=0; i--){
        if(maxi<v[i]){
            ans.push_back(v[i]);
            maxi = v[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(12);
    v.push_back(3);
    v.push_back(0);
    v.push_back(6);
    print(v);
    vector<int> ans = lead(v);
    print(ans);
    return 0;
}