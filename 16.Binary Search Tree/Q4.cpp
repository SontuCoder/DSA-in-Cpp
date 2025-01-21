// LCA in a BST :-

#include<iostream>
#include<queue>
#include<vector>
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

// Take time O(h), h-> height; in worst h ~ N or in Best h ~ logN;
void insertIntoBST(Node* &root, int data){
    if(root == NULL){
        root = new Node(data);
        return;
    }
    if(data == root->data){
        return;
    }
    if(data > root->data){
        insertIntoBST(root->r, data);
    } else {
        insertIntoBST(root->l, data);
    }
}

Node* bstBuild(vector<int> v){
    Node* root = NULL;
    for(int i: v){
        insertIntoBST(root,i);
    }
    return root;
}

Node* solve(Node* root, int n, int m){
    if(root == NULL) return NULL;
    if(root->data > n && root->data > m){
        return solve(root->l, n, m);
    }
    if(root->data < n && root->data < m){
        return solve(root->r, n, m);
    }
    return root;
}



int main(){
    vector<int> v = {50, 20, 70, 10, 30, 90, 110};
    Node* head = bstBuild(v);
    cout<<"========================"<<endl;
    infix(head);
    cout<<endl<<"========================"<<endl;
    int n, m;
    cout<<"Enter position:- ";
    cin>>n>>m;
    cout<<endl<<"========================"<<endl;
    Node* lca = solve( head, n, m);
    cout<<"LCA :- "<<((lca != NULL)? lca->data : -1) ;
    return 0;
}