#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *child[3];
    Node(int val)
    {
        data=val;      
        child[0]=NULL;  
        child[1]=NULL;  
        child[2]=NULL;  
    }
};
void preOrder(Node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preOrder(root->child[0]);
    preOrder(root->child[1]);
    preOrder(root->child[2]);
}
void inOrder(Node *root)
{
    if(root==NULL)
    return;
    inOrder(root->child[0]);
    inOrder(root->child[1]);
    cout<<root->data<<" ";
    inOrder(root->child[2]);
}
int main()
{
    Node *root=new Node(1);
    root->child[0]=new Node(2);
    root->child[1]=new Node(3);
    root->child[2]=new Node(4);
    root->child[0]->child[0]=new Node(5);//                                 1
    root->child[0]->child[1]=new Node(6);//                             /   |   \ 
    root->child[0]->child[2]=new Node(7);//                            2    3    4
    root->child[1]->child[0]=new Node(8);//                         / | \  / | \   
    root->child[1]->child[1]=new Node(9);//                        5 6  7 8 9  10
    root->child[1]->child[2]=new Node(10);
    preOrder(root);
}