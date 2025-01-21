// Minimum time to burning a tree :-

#include <iostream>
#include <queue>
#include<map>
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


// return create Mapping, return target node;
Node* createMap(Node* root, int node, map<Node*, Node*> &m){
    Node* res = NULL;
    queue<Node*> q;
    q.push(root);
    m[root] = NULL;

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->data == node){
            res = temp;
        }
        if(temp->l){
            m[temp->l] = temp;
            q.push(temp->l);
        }
        if(temp->r){
            m[temp->r] = temp;
            q.push(temp->r);
        }
    }
    return res;
}

void burnTree(Node* target, map<Node*, Node*> m, int &ans){l
    map<Node*, bool> burn;
    queue<Node*> q;
    q.push(target);
    burn[target] = true;

    while(!q.empty()){
        int size = q.size();
        bool burned = false;
        for (int i = 0; i <size ; i++)
        {
            Node* temp = q.front();
            q.pop();
            if(temp->l && !burn[temp->l]){
                burned = true;
                burn[temp->l] = true;
                q.push(temp->l);
            }
            if(temp->r && !burn[temp->r]){
                burned = true;
                burn[temp->r] = true;
                q.push(temp->r);
            }
            if(m[temp] && !burn[m[temp]]){
                burned = true;
                burn[m[temp]] = true;
                q.push(m[temp]);
            }
        }
        if (burned) {
            ans++;
        }
    }
}

int time(Node* root, int node){
    // algo :-
    // 1. create map child to perent
    // 2. find target node;
    // 3. burn tree
    map<Node*, Node*> m;
    Node* target = createMap(root, node, m);
    int ans = 0;
    burnTree(target, m, ans);
    return ans;
}


int main(){
    // 1 3 7 4 5 6 2 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 2 3 4 15 7 -1 -1 -1 -1 -1 6 -1 -1 -1
    Node *head = createLevelOrder();
    cout << endl;
    levelOrder(head);
    cout<<"=================================" << endl;
    int n1;
    cout<<"Enter nodes:- ";
    cin>>n1;
    cout<<"=================================" << endl;
    cout<<"Time taken:- "<<time(head, n1);
    return 0;
}