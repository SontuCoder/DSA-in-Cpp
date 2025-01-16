//  find the first negative number in every window of size k in an array

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

void print(const vector<int>& v){
    cout << "Vector is: ";
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;
}

vector<int> firstNegative(const vector<int>& v, int k){
    vector<int> result;
    if(v.size() < k){
        result.push_back(0);  
        return result;
    }

    deque<int> q; 
    for(int i = 0; i < k; i++){
        if(v[i] < 0) q.push_back(i);  
    }

    for(int i = k; i < v.size(); i++){
        if(!q.empty()){
            result.push_back(v[q.front()]); 
        } else {
            result.push_back(0);  
        }

        while(!q.empty() && q.front() <= i - k){
            q.pop_front();
        }

        if(v[i] < 0){
            q.push_back(i);
        }
    }

    if(!q.empty()){
        result.push_back(v[q.front()]);
    } else {
        result.push_back(0);
    }

    return result;
}

int main(){
    vector<int> q = {-8, 2, 3, -6, 5};
    print(q);
    vector<int> v = firstNegative(q, 2);
    print(v);
    return 0;
}
