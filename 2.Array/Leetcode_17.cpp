// Length of the longest subarray with zero Sum :-

// : N = 6, array[] = {9, -3, 3, -1, 6, -5}
// Result
// : 5
// Explanation
// : The following subarrays sum to zero:
// {-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}

//  N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}
// Result : 8
// Subarrays with sum 0 : {-2, 2}, {-8, 1, 7}, {-2, 2, -8, 1, 7}, {6, -2, 2, -8, 1, 7, 4, -10}

//  N = 3, array[] = {1, 0, -5}
// Result : 1
// Subarray : {0}


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int lenSubarray(vector<int> arr, int n){
    unordered_map<int, int> m;
    int preSum = 0;
    int maxLen = 0;
    for(int i =0; i<n; i++){
        preSum += arr[i];
        if(preSum == 0) {
            maxLen = i + 1;
        }
        if(m.find(preSum) != m.end()){
            maxLen = max(maxLen, i-m[preSum]);
        }else {
            m[preSum] = i;
        }
    }
    return maxLen;
}

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<"Size be:- "<<lenSubarray(arr, n)<<endl;
    return 0;
}