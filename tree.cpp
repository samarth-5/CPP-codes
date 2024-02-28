#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node* newNode(int d)
{
    Node* temp=new Node();
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void preOrder(Node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root)
{
    if(root==NULL)
    return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(Node *root)
{
    if(root==NULL)
    return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
queue<Node*>q;
void levelOrder(Node *root)
{
    q.push(root);
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left != NULL)
        q.push(temp->left);
        if(temp->right != NULL)
        q.push(temp->right);
    }
    cout<<"\n";
}
int height(Node *root)
{
    if(root==NULL)
    return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}
struct Info
{
    int d;
    int h;
};
Info* newInfo(int d,int h)
{
    Info* temp=new Info();
    temp->d=d;
    temp->h=h;
    return temp;
}
Info* diameter(Node *root)
{
    if(root==NULL)
    return newInfo(0,0);
    Info* ld=diameter(root->left);
    Info* rd=diameter(root->right);
    int selfHt=max(ld->h,rd->h)+1;
    int selfD=max(ld->h+rd->h+1,max(ld->d,rd->d));
    return newInfo(selfD,selfHt);
}
//Subtree exists in Tree or not
bool isIdentical(Node *root,Node *subRoot)
{
    if(root==NULL && subRoot==NULL)
    return true;
    else if(root==NULL || subRoot==NULL)
    return false;
    else if(root->data!=subRoot->data)
    return false;
    if(!isIdentical(root->left,subRoot->left))
    return false;
    if(!isIdentical(root->right,subRoot->right))
    return false;
    return true;
}
bool isSubTree(Node *root,Node *subRoot)
{
    if(root==NULL)
    return false;
    if(root->data==subRoot->data)
    {
        if(isIdentical(root,subRoot))
        return true;
    }
    bool left=isSubTree(root->left,subRoot);
    bool right=isSubTree(root->right,subRoot);
    return left || right;
}
int main()
{
    Node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    levelOrder(root);
    Node *subRoot=newNode(2);
    subRoot->left=newNode(4);
    subRoot->right=newNode(5);
    preOrder(root);
    cout<<"\n";
    inOrder(root);
    cout<<"\n";
    postOrder(root);
    cout<<"\nHeight:"<<height(root);
    cout<<"\nDiameter:"<<diameter(root)->d;
    cout<<"\nSubTree exists or not:"<<isSubTree(root,subRoot);
}