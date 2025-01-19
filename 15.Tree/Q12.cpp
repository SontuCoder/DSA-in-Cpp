// left View of a tree :-

#include <iostream>
#include<vector>
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

// Approach 1
vector<int> leftView(Node* head){
    vector<int> ans;
    if(head == NULL){
        return ans;
    }
    map<int, int> nodes;
    queue<pair<Node*,int>> q;
    q.push(make_pair(head, 0));
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int level = temp.second;
        if(nodes.find(level) == nodes.end()){
            nodes[level] = frontNode->data;
        }
        if(frontNode->l != NULL){
            q.push(make_pair(frontNode->l, level+1));
        }
        if(frontNode->r != NULL){
            q.push(make_pair(frontNode->r, level+1));
        }
    }

    for(auto i: nodes){
        ans.push_back(i.second);
    }
    return ans;
}

// Approach 2
vector<int> leftView2(Node* head) {
    vector<int> ans;
    if (head == NULL) {
        return ans;
    }
    queue<Node*> q;
    q.push(head);
    while (!q.empty()) {
        int n = q.size();
        // Process the first node of the current level
        for (int i = 0; i < n; i++) {
            Node* frontNode = q.front();
            q.pop();
            
            // The first node at each level is added to the result
            if (i == 0) {
                ans.push_back(frontNode->data);
            }
            
            // Push the left and right children to the queue
            if (frontNode->l != NULL) {
                q.push(frontNode->l);
            }
            if (frontNode->r != NULL) {
                q.push(frontNode->r);
            }
        }
    }

    return ans;
}

int main()
{
    // 1 3 7 4 5 6 2 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 2 3 4 5 7 -1 -1 -1 -1 -1 6 -1 -1 -1
    Node *head = createLevelOrder();
    cout << endl;
    levelOrder(head);
    cout<<"=================================" << endl;
    vector<int> v = leftView(head);
    cout<<"Ans :- ";
    for(int i: v){
        cout<<i<<" ";
    }
    return 0;
}