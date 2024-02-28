#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node *child;
};
Node* createLL(int ar[],int l)
{
    Node *head=NULL;
    for(int i=0;i<l;i++)
    {
        Node *newNode=new Node();
        newNode->data=ar[i];
        newNode->next=NULL;
        Node *temp=head;
        if(temp==NULL)
        head=newNode;
        else
        {
            while(temp->next != NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    return head;
}
void display(Node *head)
{
    Node *temp=head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
int main()
{
    int ar1[]={10,5,12,7,11};
    int ar2[]={4,20,13};
    int ar3[]={17,6};
    int ar4[]={9,8};
    int ar5[]={19,15};
    int ar6[]={2};
    int ar7[]={16};
    int ar8[]={3};
    Node *head1=createLL(ar1,sizeof(ar1)/sizeof(ar1[0]));
    display(head1);
    Node *head2=createLL(ar2,sizeof(ar2)/sizeof(ar2[0]));
    display(head2);
    Node *head3=createLL(ar3,sizeof(ar3)/sizeof(ar3[0]));
    display(head3);
    Node *head4=createLL(ar4,sizeof(ar4)/sizeof(ar4[0]));
    display(head4);
    Node *head5=createLL(ar5,sizeof(ar5)/sizeof(ar5[0]));
    display(head5);
    Node *head6=createLL(ar6,sizeof(ar6)/sizeof(ar6[0]));
    display(head6);
    Node *head7=createLL(ar7,sizeof(ar7)/sizeof(ar7[0]));
    display(head7);
    Node *head8=createLL(ar8,sizeof(ar8)/sizeof(ar8[0]));
    display(head8);
    //Connecting all LinkedLists
    //     10 -> 5 -> 12 -> 7 -> 11
    //     |                |
    //     4 -> 20 ->13    17 -> 6
    //          |    |     |
    //          2   16     9 -> 8
    //              |      |
    //              3     19 -> 15
    head1->child=head2;
    head1->next->next->next->child=head3;
    head3->child=head4;
    head4->child=head5;
    head2->next->child=head6;
    head2->next->next->child=head7;
    head7->child=head8;
}