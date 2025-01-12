// Biggest Rectangular :-

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

void print(vector<int> v){
    for(int i: v){
        cout<<i<<' ';
    }cout<<endl;
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

int main(){
    vector<int> h;
    h.push_back(2);
    // h.push_back(1);
    // h.push_back(5);
    // h.push_back(6);
    h.push_back(2);
    // h.push_back(3);
    h.push_back(2);
    h.push_back(2);

    cout<<"Area :- "<<area(h);
    return 0;
}