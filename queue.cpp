#include <iostream>
using namespace std;
#include <queue>
struct Queue
{
    int data;
    Queue *next;
};
Queue *r=NULL, *f=NULL, *nf=NULL, *nr=NULL;
void enqueue(Queue *&r,Queue *&f,int d)
{
    Queue *temp=new Queue();
    temp->data=d;
    temp->next=NULL;
    if(f==NULL)
    {
        f=temp;
        r=temp;
    }
    else
    {
        while(r->next!=NULL)
        {
            r=r->next;
        }
        r->next=temp;
        r=temp;
    }
}
void dequeue(Queue *&f)
{
    f=f->next;
}
void moveNfront(Queue *&f,int n,Queue *&nf)
{
    Queue *temp=f;
    for(int i=0;i<n-1;i++)
    {
        enqueue(nr,nf,temp->data);
        temp=temp->next;
    }
    int d=temp->data;
    temp=temp->next;
    while(temp!=NULL)
    {
        enqueue(nr,nf,temp->data);
        temp=temp->next;
    }
    f=NULL,r=NULL;
    enqueue(r,f,d);
    while(nf != NULL)
    {
        enqueue(r,f,nf->data);
        nf=nf->next;
    }
}
void display(Queue *f)
{
    Queue *temp=f;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
}
int main()
{
    enqueue(r,f,6);
    enqueue(r,f,1);
    enqueue(r,f,7);
    enqueue(r,f,2);
    enqueue(r,f,8);
    moveNfront(f,3,nf);
    display(f);
}