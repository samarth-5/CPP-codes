#include <iostream>
using namespace std;
struct Stack
{
    int data;
    Stack *next;
};
Stack *top=NULL;
Stack *rev=NULL;
void push(Stack *&top,int d)
{
    Stack *temp=new Stack();
    temp->data=d;
    if(top==NULL)
    {
        temp->next=NULL;
        top=temp;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}
void pop(Stack *&top)
{
    int data=top->data;
    top=top->next;
}
void display(Stack *top)
{
    while(top!=NULL)
    {
        cout<<top->data<<"\n|\n";
        top=top->next;
    }
}
void revStack(Stack *top,Stack *&rev)
{
    while(top!=NULL)
    {
        push(rev,top->data);
        top=top->next;
    }
}
int palindrome(Stack *top,Stack *rev)
{
    while(top!=NULL && rev!=NULL)
    {
        if(top->data!=rev->data)
        return 0;
        else
        {
            top=top->next;
            rev=rev->next;
        }
    }
    return 1;
}
int main()
{
    push(top,1);
    push(top,9);
    push(top,1);
    push(top,7);
    display(top);
    pop(top);
    cout<<"\n";
    display(top);
    revStack(top,rev);
    if(palindrome(top,rev)==1)
        cout<<"Palindrome";
    else
        cout<<"Not Palindrome";
}