// Check for Balanced Btree :-

#include<iostream>
#include<queue>
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

Node* createLevelOrder(){
    cout << "Enter value:- ";
    int n;
    cin >> n;
    if (n == -1)
    {
        return NULL;
    }

    Node *node = new Node(n);
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        Node* ptr = q.front();
        q.pop();
        cout << "Enter value left of "<<ptr->data<<" :- ";
        cin >> n;
        if (n != -1)
        {
            ptr->l = new Node(n);
            q.push(ptr->l);
        }
        cout << "Enter value right of "<<ptr->data<<" :- ";
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
pair<int,bool> balncedTree(Node* head){
    if(head == NULL){
        return {0,true};
    }

    pair<int, bool> left = balncedTree(head->l);
    pair<int, bool> right = balncedTree(head->r);
    pair<int, bool> node;
    node.first = max(left.first, right.first) +1;
    node.second = (left.second && right.second) && (abs(left.first-right.first)<=1);

    return node;
}



int main(){
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* head = createLevelOrder();
    cout<<endl;
    levelOrder(head);
    cout<<endl;
    pair<int,int> node = balncedTree(head);
    cout<<"Diameter:- "<<node.second;
    
    return 0;
}