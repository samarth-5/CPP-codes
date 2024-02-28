#include<iostream>
#include<stack>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node* newNode(int d)
{
    Node *temp=new Node();
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void preOrder(Node *root)
{
    stack<Node*>s;
    s.push(root);
    while(!s.empty())
    {
        Node *temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right!=NULL)
        s.push(temp->right);
        if(temp->left!=NULL)
        s.push(temp->left);
    }
    cout<<"\n";
}
void inOrder(Node *root)
{
    stack<Node*>s;
    Node* temp=root;
    while(temp!=NULL || !s.empty())
    {
        while (temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top(); 
        cout<<temp->data<<" "; 
        s.pop();
        temp=temp->right;
    }
    cout<<"\n";
}
void postOrder(Node *root)
{
    stack<Node*>s1;
    stack<Node*>s2;
    s1.push(root);
    while(!s1.empty())
    {
        Node *temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left!=NULL)
        s1.push(temp->left);
        if(temp->left!=NULL)
        s1.push(temp->right);
    }
    while(!s2.empty())
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}
int main()
{
    Node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    preOrder(root);
    inOrder(root);
    postOrder(root);
}