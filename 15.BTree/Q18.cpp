// LCA -> Lowest common ansystor :-

#include <iostream>
#include<limits.h>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *l;
    Node *r;

    Node(int val)
    {
        this->data = val;
        this->l = NULL;
        this->r = NULL;
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

Node *createLevelOrder()
{
    cout << "Enter value:- ";
    int n;
    cin >> n;
    if (n == -1)
    {
        return NULL;
    }

    Node *node = new Node(n);
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        Node *ptr = q.front();
        q.pop();
        cout << "Enter value left of " << ptr->data << " :- ";
        cin >> n;
        if (n != -1)
        {
            ptr->l = new Node(n);
            q.push(ptr->l);
        }
        cout << "Enter value right of " << ptr->data << " :- ";
        cin >> n;
        if (n != -1)
        {
            ptr->r = new Node(n);
            q.push(ptr->r);
        }
    }
    return node;
}

int kTh(Node* root, int n1, int &k){
    if(root== NULL) return -1;

    if(root->data == n1){
        return root->data;
    }

    int left = kTh(root->l, n1, k);
    int right = kTh(root->r, n1, k);
        if(left != -1 && right == -1){
            k--;
            if(k<=0){
                k = INT_MAX;
                return root->data;
            }
            return left;
        }
        if(left == -1 && right != -1){
            k--;
            if(k<=0){
                k = INT_MAX;
                return root->data;
            }
            return right;
        }
        return -1;
}



int main(){
    // 1 3 7 4 5 6 2 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 2 3 4 15 7 -1 -1 -1 -1 -1 6 -1 -1 -1
    Node *head = createLevelOrder();
    cout << endl;
    levelOrder(head);
    cout<<"=================================" << endl;
    int n1,k;
    cout<<"Enter nodes:- ";
    cin>>n1>>k;
    cout<<"=================================" << endl;
    cout<<"kTh :- "<<kTh(head, n1, k);

}