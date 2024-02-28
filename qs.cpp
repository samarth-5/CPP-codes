#include<iostream>
using namespace std;
void swap(int ar[],int i,int j)
{
    int temp=ar[i];
    ar[i]=ar[j];
    ar[j]=temp;
}
int partition(int ar[],int l,int r)
{
    int pivot=ar[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(ar[j]<pivot)
        {
            i++;
            swap(ar,i,j);
        }
    }
    swap(ar,i+1,r);
    return i+1;
}
void quickSort(int ar[],int l,int r)
{
    if(l<r)
    {
        int idx=partition(ar,l,r);
        quickSort(ar,l,idx-1);
        quickSort(ar,idx+1,r);
    }
}
int main()
{
    int ar[]={5,4,3,2,1};
    quickSort(ar,0,4);
    for(int i=0;i<5;i++)
    cout<<ar[i]<<" ";
}