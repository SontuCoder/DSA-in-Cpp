// Sum of all nodes of longest path :-

#include <iostream>
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

pair<int, int> sumPair(Node* root){
    if(root == NULL){
        return {0,0};
    }

    pair<int,int> left = sumPair(root->l);
    pair<int,int> right = sumPair(root->r);
    pair<int,int> ans;   // {sum, height}
    
    if (left.second > right.second) {
        return {root->data + left.first, left.second + 1};
    } 
    if (left.second < right.second) {
        return {root->data + right.first, right.second + 1};
    } 

    // If both heights are equal, choose the one with the greater sum
    return {root->data + max(left.first, right.first), left.second + 1};
}

int main(){
    // 1 3 7 4 5 6 2 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 2 3 4 15 7 -1 -1 -1 -1 -1 6 -1 -1 -1
    Node *head = createLevelOrder();
    cout << endl;
    levelOrder(head);
    cout<<"=================================" << endl;
    pair<int,int> v = sumPair(head);
    cout<<"sum:- "<<v.first;

}