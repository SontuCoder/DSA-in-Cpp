// Kth smallest element in a BST :-

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

int solve(Node* root, int& count, int k){
    if(root == NULL){
        return -1;
    }
    int left =  solve(root->l, count, k);

    if(left != -1){
        return left;
    }
    count++;
    if(count==k){
        return root->data;
    }
    return solve(root->r, count, k);
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
    int count = 0;
    cout<<"Valid BST or not:- "<<solve(head, count, n);
    return 0;
}