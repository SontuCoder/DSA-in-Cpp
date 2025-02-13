// Falttan BST in sorted List :-

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
// ==========================================
// ==========================================

void inorder(Node* head, vector<int> &i){
    if(head == NULL) return;
    inorder(head->l, i);
    i.push_back(head->data);
    inorder(head->r, i);
}


Node* twoSum(Node* head){
    vector<int> i;
    inorder(head,i);
    return bstBuild(i);
}


int main(){
    vector<int> v = {10,6,2,8,12,11,15};
    Node* head = bstBuild(v);
    cout<<"========================"<<endl;
    infix(head);
    cout<<endl<<"========================"<<endl;
    cout<<endl<<"========================"<<endl;
    Node* ans = twoSum(head);
    infix(head);
    return 0;
}
