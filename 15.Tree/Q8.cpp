// Boundary Traversal :-

#include <iostream>
#include <queue>
#include<stack>
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

void printLeftBoundary(Node* root) {
    Node* curr = root->l;
    while (curr) {
        if (curr->l || curr->r) {
            cout << curr->data << " ";
        }
        if (curr->l) {
            curr = curr->l;
        } else {
            curr = curr->r;
        }
    }
}

void printLeafNodes(Node* root) {
    if (root == NULL) return;
    if (root->l == NULL && root->r == NULL) {
        cout << root->data << " ";
        return;
    }
    printLeafNodes(root->l);
    printLeafNodes(root->r);
}

void printRightBoundary(Node* root) {
    stack<int> s;
    Node* curr = root->r;
    while (curr) {
        if (curr->l || curr->r) {
            s.push(curr->data);
        }
        if (curr->r) {
            curr = curr->r;
        } else {
            curr = curr->l;
        }
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

// Approach 1
void boundaryTraversal(Node* root) {
    if (root == NULL) return;
    
    cout << root->data << " "; // Print root

    // Print left boundary
    printLeftBoundary(root);
    
    // Print leaf nodes
    printLeafNodes(root);

    // Print right boundary
    printRightBoundary(root);
}

int main()
{
    // 1 3 7 4 5 6 2 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 2 3 4 5 7 -1 -1 -1 -1 -1 6 -1 -1 -1
    Node *head = createLevelOrder();
    cout << endl;
    levelOrder(head);
    cout<<"=================================" << endl;
    boundaryTraversal(head);
    return 0;
}