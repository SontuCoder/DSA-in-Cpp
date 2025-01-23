// Find the row with maximum number of 1's

#include<iostream>
#include<vector>
using namespace std;


int solve(vector<vector<int>> v){
    int row = v.size()-1;
    int col = v[0].size()-1;
    int colNum = col;
    int rowNum = 0;
    int rowPoint = -1;
    while(rowNum<=row && colNum>=0){
        if(v[rowNum][colNum] == 1){
            colNum--;
            rowPoint = rowNum;
        } else {
            rowNum++;
        }
    }
    return rowPoint;
}

int main(){
    vector<vector<int>> v = {{0,0},{0,0}};
    cout<<"Ans :- "<<solve(v);
    return 0;
}