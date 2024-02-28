// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};
Node *head=NULL;
Node *tail=NULL;
void insertFirst(Node *&head, Node *&tail,int d)
{
    Node *temp=new Node();
    temp->data=d;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        temp->prev=NULL;
        head=temp;
    }    
}
void insertLast(Node *&head, Node *&tail,int d)
{
    Node *temp=new Node();
    temp->data=d;
    temp->next=NULL;
    if(tail==NULL)
    {
        temp->prev=NULL;
        head=temp;
        tail=temp;
    }
    else
    {
        temp->prev=tail;
        tail->next=temp;
        tail=temp;        
    }
}
void insertPos(Node *&head,Node *&tail, int d,int p)
{
    Node *temp=new Node();
    temp->data=d;
    Node *newTemp=head;
    for(int i=1;i<p-1;i++)
    {
        newTemp=newTemp->next;
    }
    temp->next=newTemp->next;
    temp->prev=newTemp;
    newTemp->next=temp;
    (newTemp->next)->prev=temp;
}
void display(Node *head,Node *tail)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
int main()
{
    insertFirst(head,tail,5);
    insertFirst(head,tail,9);
    insertFirst(head,tail,1);
    insertLast(head,tail,4);
    insertPos(head,tail,7,3);
    display(head,tail);
}