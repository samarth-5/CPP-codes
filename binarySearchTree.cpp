#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left,*right;
};
Node* newNode(int data)
{
    Node *temp=new Node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void insertBst(Node *&root,int d)
{
    if(root==NULL)
    {
        root=newNode(d);
        return;
    }
    if(d<root->data)
    insertBst(root->left,d);
    else if(d>root->data)
    insertBst(root->right,d);
}
Node* findInorderSuccessor(Node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
Node* deleteBst(Node *&root,int d)
{
    if(root==NULL)
    {
        return NULL;
    } 
    if(d < root->data)
    root->left=deleteBst(root->left,d);
    else if(d > root->data)
    root->right=deleteBst(root->right,d);
    else
    {
        //case1-no child(leaf node)
        if(root->left==NULL && root->right==NULL)
        return NULL;
        //case2-single child
        if(root->left==NULL)
        return root->right;
        else if (root->right==NULL)
        return root->left;
        //case3-both child
        Node* fis=findInorderSuccessor(root->right);
        root->data=fis->data;
        root->right=deleteBst(root->right,fis->data);
    }
    return root;
}
void inOrder(Node *root)
{
    if(root==NULL)
    return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int main()
{
    Node *root;
    int ar[]={8,5,3,1,4,6,10,11,14};
    for(int i=0;i<9;i++)
    insertBst(root,ar[i]);
    deleteBst(root,10);    
    inOrder(root);
}