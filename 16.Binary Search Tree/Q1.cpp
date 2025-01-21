// Valid Bst or not :-

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

void levelOrder(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(head);
    q.push(NULL);
    while (!q.empty())
    {
        Node *ptr = q.front();
        q.pop();

        if (ptr == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << ptr->data << " ";
            if (ptr->l != NULL)
            {
                q.push(ptr->l);
            }
            if (ptr->r != NULL)
            {
                q.push(ptr->r);
            }
        }
    }
}

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

bool valid(Node* head, int mini, int maxi){
    if(head == NULL) return true;
    if(head->data > mini && head->data <maxi){
        return valid(head->l, mini, head->data) && valid(head->r, head->data, maxi);
    }
    return false;
}

bool isValid(Node* head){
    if(head == NULL){
        return true;
    }
    int mini = 0; // minimum range
    int maxi = INT_MAX; // maximun range
    return valid(head, mini, maxi);
}


int main(){
    vector<int> v = {50, 20, 70, 10, 30, 90, 110};
    Node* head = bstBuild(v);
    cout<<"========================"<<endl;
    levelOrder(head);
    cout<<"========================"<<endl;
    infix(head);
    cout<<endl<<"========================"<<endl;
    cout<<"Valid BST or not:- "<<isValid(head);
    return 0;
}