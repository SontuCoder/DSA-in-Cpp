// Largest BST in a Btree :-

#include<iostream>
#include<queue>
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

class Result{
    public:
    int maxi;
    int mini;
    int size;
    bool isBST;

    Result(){
        this->mini = INT_MAX;
        this->maxi = INT_MIN;
        this->size = 0;
        this->isBST = true;
    }
};

Result* LongBst(Node* root){
    if(root == NULL){
        Result* res = new Result();
        return res;
    }

    Result* left = LongBst(root->l);
    Result* right = LongBst(root->r);
    Result* res = new Result();

    if (root->l == NULL && root->r == NULL) {
        res->mini = root->data;
        res->maxi = root->data;
        res->size = 1;
        return res;
    }
    
    if((left->maxi < root->data && right->mini > root->data) && (left->isBST && right->isBST)){
        res->size =  left->size + right->size + 1;
    } else {
        res->isBST = false;
        res->size = max(left->size, right->size);
    }
    res->maxi = max(root->data, right->maxi);
    res->mini = min(root->data, left->mini);

    return res;
}


int main(){
    vector<int> v = {50, 20, 70, 10, 30, 90, 110};
    Node* head = bstBuild(v);
    cout<<"========================"<<endl;
    infix(head);
    cout<<endl<<"========================"<<endl;
    Result* lca = LongBst(head);
    cout<<"Longest BST :- "<< lca->size;
    return 0;
}