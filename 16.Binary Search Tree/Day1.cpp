// Build BST from array :-

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

// Take time O(h), h-> height; in worst h ~ N or in Best h ~ logN; 
bool searchInBST(Node* &root,int data){
    if(root == NULL){
        return false;
    }

    if(root->data == data){
        return true;
    } if(root->data > data){
        return searchInBST(root->l, data);
    } else {
        return searchInBST(root->r, data);
    }
}

Node* predecessor(Node* root){
    Node* temp = root->l;
    while(temp->r != NULL){
        temp = temp->r;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int key) {
    if (root == NULL) return root;  // Base case

    if (key < root->data) {
        root->l = deleteFromBST(root->l, key);
    } 
    else if (key > root->data) {
        root->r = deleteFromBST(root->r, key);
    } 
    else { 
        // Case 1: Node has no child (leaf node)
        if (root->l == NULL && root->r == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: Node has only one child
        else if (root->l == NULL) {  // Only r child
            Node* temp = root->r;
            delete root;
            return temp;
        } 
        else if (root->r == NULL) {  // Only l child
            Node* temp = root->l;
            delete root;
            return temp;
        }
        // Case 3: Node has two children
        else {
            Node* temp = predecessor(root); // Find predecessor
            // Node* temp = successor(root); //Smallest value in its r subtree
            root->data = temp->data;  // Copy predecessor's value to root
            root->l = deleteFromBST(root->l, temp->data); // Delete predecessor
        }
    }
    return root;
}



int main(){
    vector<int> v = {50, 20, 70, 10, 30, 90, 110};
    Node* head = bstBuild(v);
    cout<<"========================"<<endl;
    levelOrder(head);
    cout<<"========================"<<endl;
    infix(head);
    cout<<"========================"<<endl;
    int n;
    cout<<" Enter data to search :- ";
    cin>>n;
    cout<<"Present or not :- "<<searchInBST(head, n)<<endl;
    cout<<"========================"<<endl;
    head = deleteFromBST(head, 50);
    infix(head);
    return 0;
}