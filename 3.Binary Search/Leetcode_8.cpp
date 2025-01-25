// Aggrasive Cow problem :-


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPosiblePos(vector<int> pos, int cow, int dist){
    int cowCount = 1;
    int lastPos = pos[0];

    for(int i = 0; i<pos.size(); i++){
        if(pos[i]-lastPos >= dist){
            cowCount++;
            lastPos = pos[i];
        }
    }
    return cowCount>=cow;
}


int dist(vector<int> pos, int cow){
    int i = 0;
    sort(pos.begin(), pos.end());
    int j = (max(pos.begin(), pos.end()) - min(pos.begin(), pos.end()));
    int ans = -1;
    while(i<=j){
        int mid = i+(j-i)/2;
        if(isPosiblePos(pos, cow, mid)){
            ans = mid;
            i = mid+1;
        } else {
            j = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> pos = {4, 2, 1, 3, 6};
    int cow = 2;
    cout<<"The maximum Distance:- "<< dist(pos,cow);
    return 0;
}

