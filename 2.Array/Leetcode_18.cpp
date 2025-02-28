// Merge Overlapping Sub-intervals
// Example 1:
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]

// Example 2:
// Input: [[1,4],[4,5]]
// Output:[[1,5]]

#include<iostream>
#include<vector>
using namespace std;

void print(vector<pair<int,int>>& arr) {
    for(auto p : arr) {
        cout << "[" << p.first << "," << p.second << "] ";
    }
    cout << endl;
}

vector<pair<int,int>> margeInteervals(vector<pair<int,int>> arr){
    // Sort intervals based on the starting point
    sort(arr.begin(), arr.end());
    
    vector<pair<int,int>> ans;
    for(auto i: arr){
        if(ans.empty()){
            ans.push_back(i);
        } else {
            pair<int,int> &last = ans.back();
            if(last.second >= i.first){
                last.second = max(last.second, i.second);
            } else {
                ans.push_back(i);
            }
        }
    }
    return ans;
}

int main(){
    vector<pair<int,int>> arr;
    int n;
    cout<<"Enter size: ";
    cin>>n;
    cout<<"Enter intervals: ";
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr.push_back({x,y});
    }
    print(arr);
    vector<pair<int,int>> ans = margeInteervals(arr);
    print(ans);
    return 0;
}