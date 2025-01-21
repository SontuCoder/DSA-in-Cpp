// Predecessor and Successor of a Node in a BST :-

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

int predecessor(Node* root){
    if(root == NULL || root->l == NULL) return -1;

    Node* pred = root->l;
    while(pred->r != NULL){
        pred = pred->r;
    }
    return pred->data;
}

int successor(Node* root){
    if(root == NULL || root->r == NULL) return -1;

    Node* pred = root->r;
    while(pred->l != NULL){
        pred = pred->l;
    }
    return pred->data;
}

pair<int,int> solve(Node* root, int k){
    if(root == NULL) return {-1,-1};

    int pred = -1;
    int succ = -1;

    while( root->data != k){
        if(root->data > k){
            succ = root->data;
            root = root->l;
        }else {
            pred = root->data;
            root = root->r;
        }
    }
    pred = (predecessor(root)!= -1) ? predecessor(root) : pred;

    succ = (successor(root)!= -1) ? successor(root) : succ;
    return {pred, succ};
}


int main(){
    vector<int> v = {50, 20, 70, 10, 30, 90, 110};
    Node* head = bstBuild(v);
    cout<<"========================"<<endl;
    infix(head);
    cout<<endl<<"========================"<<endl;
    int n;
    cout<<"Enter position:- ";
    cin>>n;
    cout<<endl<<"========================"<<endl;
    pair<int,int> p = solve(head, n);
    cout<<"Pressesor and Successor :- "<<p.first<<" "<<p.second;
    return 0;
}