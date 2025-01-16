// First non-repeating chararter in a stream

#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

string repeat(string s){
    unordered_map<char, int> count;
    queue<char> q;

    string ans = "";
    for(int i = 0; i<s.size(); i++){
        char ch = s[i];
        count[ch]++;
        q.push(ch);
        while(!q.empty()){
            if(count[q.front()]>1){
                q.pop();
            }else{
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
    cout<<"Enter String:- ";
    string s;
    cin>>s;
    cout<<s<<endl;
    cout<<repeat(s);
    return 0;
}