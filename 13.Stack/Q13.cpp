// Maximum Area in a Binary Matrix :-


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> previouSmall(vector<int> h, int n){
    stack<int> s;
    s.push(-1);
    vector<int> v(n);
    
    for(int i = 0; i<n; i++){

        while (s.top()!= -1 && h[s.top()]>= h[i])
        {
            s.pop();
        }
        v[i] = s.top();
        s.push(i);
    }
    return v;
}

vector<int> nextSmall(vector<int> h, int n){
    stack<int> s;
    s.push(-1);
    vector<int> v(n);
    
    for(int i = n-1; i>=0; i--){
        while (s.top() != -1 && h[s.top()] >= h[i]){
            s.pop();
        }
        v[i] = s.top();
        s.push(i);
    }
    return v;
}

int area(vector<int> h){
    int n = h.size();

    vector<int> prev = previouSmall(h, n);
    vector<int> next = nextSmall(h, n); 

    int area = -1;
    for(int i = 0; i<n; i++){
        int l = h[i];
        if(next[i] == -1){
            next[i] = n;
        }
        int w = next[i] - prev[i] -1;
        area = max(area, (l*w));
    }
    return area;
}


int maxArea(vector<vector<int>> v){
    int a = area(v[0]);
    int n = v[0].size();

    for(int i = 1; i<n; i++){

        // Update row value
        for(int j = 0; j<n; j++){
            if(v[i][j] != 0){
                v[i][j] += v[i-1][j];
            }
        }

        // retrive new max area
        a = max(a, area(v[i]));
    }
    return a;
}

int main(){
    vector<vector<int>> v(4, vector<int>(4));
    v[0][0] = 0;
    v[0][1] = 1;
    v[0][2] = 1;
    v[0][3] = 0;
    v[1][0] = 1;
    v[1][1] = 1;
    v[1][2] = 1;
    v[1][3] = 1;
    v[2][0] = 1;
    v[2][1] = 1;
    v[2][2] = 1;
    v[2][3] = 1;
    v[3][0] = 1;
    v[3][1] = 1;
    v[3][2] = 0;
    v[3][3] = 0;

    cout<<"Max area :- "<<maxArea(v);
    return 0;
}