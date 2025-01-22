// marge two BST :-

// Approach 1 :-
// 1. Extract two inoder array of two BST
// 2. Marge two inorder Array
// 3. Build BST from marger inorder array

// Approach 2 :-
// 1. Convert BST in sorted LL;
// 2. marge two LL in one sorted LL;
// 3. Convert LL to BST;

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


// Approach 1
void inorder(Node* head, vector<int> &v){
    if(head == NULL) return;

    inorder(head->l,v);
    v.push_back(head->data);
    inorder(head->r,v);
}

vector<int> marge(vector<int> m, vector<int> n){
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i<m.size() && j<n.size()){
        if(m[i]<n[j]){
            ans.push_back(m[i++]);
        } else {
            ans.push_back(n[j++]);
        }
    }
    while(j<n.size()){
        ans.push_back(n[j++]);
    }
    while(i<m.size()){
        ans.push_back(m[i++]);
    }
    return ans;
}

Node* buildBst(vector<int> ans, int l, int r){
    if(l>r) return NULL;
    int mid = r+(l-r)/2;
    Node* root = new Node(ans[mid]);
    root->l = buildBst(ans, l, mid-1);
    root->r = buildBst(ans, mid+1,r);
    return root; 
}

Node* solve(Node* head1, Node* head2){
    vector<int> v1 ;
    inorder(head1, v1);
    vector<int> v2 ;
    inorder(head2, v2);
    vector<int> margeInorder = marge(v1,v2);
    return buildBst(margeInorder, 0, margeInorder.size()-1);
}


// Approach 2

Node* bstLL(Node* head, Node* &h){
    if(head == NULL) return NULL;
    bstLL(head->r, h);
    head->r = h;
    if(h != NULL){
        h->l = head;
    }
    h = head;
    bstLL(head->l, h);
    return h;
}

Node* margeLL(Node* head1, Node* head2){
    Node* head = new Node(1);
    Node* ptr = head;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            ptr->r = head1;
            head1->l = ptr;
            head1 = head1->r;
        } else {
            ptr->r = head2;
            head2->l = ptr;
            head2 = head2->r;
        }
        ptr = ptr->r;
    } 
    if (head1 != NULL) ptr->r = head1;
    if (head2 != NULL) ptr->r = head2;

    Node* ans = head->r;
    if (ans != NULL) ans->l = NULL;
    
    delete head; 
    return ans;
}

int length(Node* head){
    int n = 0;
    while(head != NULL){
        n++;
        head = head->r;
    }
    return n;
}

Node* buildBSTll(Node* &head, int n){
    if(n<= 0 || head == NULL) return NULL;

    Node* left = buildBSTll(head, n/2);
    Node* root = head;
    root->l = left;
    head = head->r;
    root->r = buildBSTll(head, n- n/2 -1);
    return root;
}

Node* solve2(Node* head1, Node* head2){
    Node* h1 = NULL;
    h1=  bstLL(head1, h1);
    
    Node* h2 = NULL;
    h2 = bstLL(head2,h2);

    Node* margeHead = margeLL(h1, h2);
    int n = length(margeHead);
    return buildBSTll(margeHead,n);
}

int main(){
    vector<int> v1 = {50, 20, 70, 10, 30, 90, 110};
    vector<int> v2 = {40, 25, 75, 15, 35, 95, 115};
    Node* head1 = bstBuild(v1);
    Node* head2 = bstBuild(v2);
    cout<<"========================"<<endl;
    infix(head1);
    cout<<endl<<"========================"<<endl;
    infix(head2);
    cout<<endl<<"========================"<<endl;
    cout<<endl<<"========================"<<endl;
    Node* lca = solve2( head1, head2);
    infix(lca);
    return 0;
}