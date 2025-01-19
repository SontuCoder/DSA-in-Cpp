// Zic zac Traversal :-

#include <iostream>
#include <queue>
#include<deque>
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

// Approach 1
void zigZag(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    deque<Node *> dq;
    dq.push_back(head);
    bool leftToRight = true;

    while(!dq.empty()){
        int size = dq.size();
        for(int i = 0; i<size; i++){
            if(leftToRight){
                Node* ptr = dq.front();
                dq.pop_front();
                cout<<ptr->data<<" ";
                if(ptr->l != NULL){
                    dq.push_back(ptr->l);
                }
                if(ptr->r != NULL){
                    dq.push_back(ptr->r);
                }
            } else {
                Node* ptr = dq.back();
                dq.pop_back();
                cout<<ptr->data<<" ";
                if(ptr->r != NULL){
                    dq.push_front(ptr->r);
                }
                if(ptr->l != NULL){
                    dq.push_front(ptr->l);
                }
            }
        }
        leftToRight = !leftToRight;
        cout<<endl;
    }
}

int main()
{
    // 1 3 7 4 5 6 2 -1 -1 -1 -1 -1 -1 -1 -1
    Node *head = createLevelOrder();
    cout << endl;
    levelOrder(head);
    cout<<"=================================" << endl;
    zigZag(head);
    return 0;
}