#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insert(int *ar,int si,int ei)
{
    if(si>ei)
    return NULL;
    int mid=(si+ei)/2;
    Node* root=new Node(ar[mid]);
    root->left=insert(ar,si,mid-1);
    root->right=insert(ar,mid+1,ei);
    return root;
}
void preOrder(Node* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    int ar[]={7,1,3,2,4,6,5};
    sort(ar,ar+7);
    int si=0,ei=6;
    Node* root=insert(ar,si,ei);
    preOrder(root);
}