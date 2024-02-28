#include <iostream>
using namespace std;
void swap(int &a,int &b)
{
    int c=a;
    a=b;
    b=c;
}
int partition(int ar[],int l,int h)
{
    int pivot=ar[h],i=l-1;
    for(int j=l;j<h;j++)
    {
        if(ar[j] < pivot)
        {
            i++;
            swap(ar[i],ar[j]);
        }
    }
    swap(ar[i+1],ar[h]);
    return i+1;
}
void quickSort(int ar[],int l,int h)
{
    if(l<h)
    {
        int q=partition(ar,l,h);
        quickSort(ar,l,q-1);
        quickSort(ar,q+1,h);
    }
}
void display(int ar[])
{
    for(int i=0;i<8;i++)
    cout<<ar[i]<<" ";
}
int main()
{
    int ar[]={2,8,7,1,3,5,6,4};
    quickSort(ar,0,7);
    display(ar);
}