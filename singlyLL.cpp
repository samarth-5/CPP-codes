// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head=NULL;
void insertFirst(Node *&head,int d)
{
    Node *temp=new Node();
    temp->data=d;
    if(head==NULL)
    head=temp;
    else
    {
        temp->next=head;
        head=temp;
    }
}
void insertLast(Node *&head,int d)
{
    Node *newTemp=new Node();
    newTemp->data=d;
    newTemp->next=NULL;
    if(head==NULL)
    head=newTemp;
    else
    {
        Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newTemp;
    }
}
void insertPosition(Node *&head,int d,int p)
{
    Node *newTemp=new Node();
    newTemp->data=d;
    Node *temp=head;
    for(int i=1;i<p-1;i++)
    {
        temp=temp->next;
    }
    newTemp->next=temp->next;
    temp->next=newTemp;
}
void display(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void sort(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        Node *curr=temp->next;
        while(curr!=NULL)
        {
            if((temp->data)>(curr->data))
            {
                int z=temp->data;
                temp->data=curr->data;
                curr->data=z;
            }
            curr=curr->next;
        }
        temp=temp->next;
    }
}
void deleteFirst(Node *&head)
{
    head=head->next;
}
void deleteLast(Node *&head)
{
    Node *temp=head;
    while((temp->next)->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}
void deletePosition(Node *&head,int p)
{
    Node *temp=head;
    for(int i=1;i<p-1;i++)
    {
        temp=temp->next;
    }
    temp->next=(temp->next)->next;
}
int main() 
{
    insertFirst(head,3);
    insertFirst(head,6);
    insertLast(head,7);
    insertLast(head,4);
    insertFirst(head,8);
    insertLast(head,9);
    insertPosition(head,5,3);
    display(head);
    cout<<"\n";
    sort(head);
    display(head);
    cout<<"\n";
    deleteFirst(head);
    display(head);
    cout<<"\n";
    deleteLast(head);
    display(head);
    cout<<"\n";
    deletePosition(head,3);
    display(head);
}