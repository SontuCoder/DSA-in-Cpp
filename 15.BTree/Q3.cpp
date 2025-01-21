// Diameter of a Btree :-

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

int  height(Node* head){
    if(head == NULL){
        return 0;
    }
    return max(height(head->r),height(head->l)) +1;
}

// Approach 1
int diameter(Node* head){
    if(head== NULL){
        return 0;
    }
    int op1 = diameter(head->l);
    int op2 = diameter(head->r);
    int op3 = height(head->l)+height(head->r)+1;
    return max(op1, max(op2, op3));
}


// Approach 2
pair<int, int> diameter2(Node* head) {
    if (head == NULL) {
        return {0, 0};  // {diameter, height}
    }

    pair<int, int> left = diameter2(head->l);
    pair<int, int> right = diameter2(head->r);

    int height = max(left.second, right.second) + 1;
    int dia = max(left.first, max(right.first, height));

    return {dia, height};
}



int main(){
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* head = createLevelOrder();
    cout<<endl;
    levelOrder(head);
    cout<<endl;
    pair<int,int> dia = diameter2(head);
    cout<<"Diameter:- "<<dia.first;
    
    return 0;
}