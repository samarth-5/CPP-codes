#include <iostream>
using namespace std;
struct Node
{
    int coef;
    int x;
    int y;
    Node *next;
};
Node *h1=NULL;
Node *h2=NULL;
Node *h3=NULL;

void insertLast(int coef,int x,int y,Node *&head)
{
    Node *temp=new Node();
    temp->coef=coef;
    temp->x=x;
    temp->y=y;
    temp->next=NULL;
    Node *newTemp=head;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(newTemp->next!=NULL)
        {
            newTemp=newTemp->next;
        }
        newTemp->next=temp;
    }
}
void display(Node *head)
{
    Node *temp=head;
    while(temp !=  NULL)
    {
        cout<<temp->coef<<"x"<<temp->x<<"y"<<temp->y<<"\n";
        temp=temp->next;
    }
}

void add(Node *h1,Node *h2,Node *&h3)
{
    Node *temp=new Node();
    Node *temp1=h1;
    Node *temp2=h2;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->x > temp2->x)
        {
            insertLast(temp1->coef,temp1->x,temp1->y,h3);
            temp1=temp1->next;
        }
        else if(temp2->x > temp1->x)
        {
            insertLast(temp2->coef,temp2->x,temp2->y,h3);
            temp2=temp2->next;
        }
        else if(temp1->y > temp2->y)
        {
            insertLast(temp1->coef,temp1->x,temp1->y,h3);
            temp1=temp1->next;
        }
        else if(temp2->y > temp1->y)
        {
            insertLast(temp2->coef,temp2->x,temp2->y,h3);
            temp2=temp2->next;
        }
        else
        {
            temp->coef=temp1->coef+temp2->coef;
            insertLast(temp->coef,temp1->x,temp1->y,h3);
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    while(temp1 != NULL)
    {
        insertLast(temp1->coef,temp1->x,temp1->y,h3);
        temp1=temp1->next;
    }
    while(temp2 != NULL)
    {
        insertLast(temp2->coef,temp2->x,temp2->y,h3);
        temp2=temp2->next;
    }
}
int main()
{
    insertLast(2,2,1,h1);
    insertLast(3,1,2,h1);
    insertLast(4,1,1,h1);
    insertLast(9,0,0,h1);

    insertLast(3,3,0,h2);
    insertLast(2,2,1,h2);
    insertLast(2,1,2,h2);
    insertLast(7,0,0,h2);
    
    add(h1,h2,h3);
    display(h3);
}