// Make bst from Preorder :-

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Node{
    public:
    int data;
    Node* l;
    Node* r;

    Node(int val){
        this->data = val;
        this->r = NULL;
        this->l = NULL;
    }
};

void infix(Node *head)
{
    if (head != NULL)
    {
        infix(head->l);
        cout << head->data << " ";
        infix(head->r);
    }
    else
    {
        return;
    }
}

Node* solve(vector<int>& v, int mini, int maxi, int& index){
    if(index>=v.size()) return NULL;
    if(v[index]<mini || v[index]> maxi){
        return NULL;
    }
    Node* root = new Node(v[index++]);
    root->l = solve(v, mini, root->data, index);
    root->r = solve(v, root->data, maxi, index);
    return root;
}


Node* bstBuild(vector<int> v){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int index = 0;
    return solve(v, mini, maxi, index); 
}


int main(){
    vector<int> v = {10,6,2,8,12,11,15};
    Node* head = bstBuild(v);
    infix(head);
    return 0;
}