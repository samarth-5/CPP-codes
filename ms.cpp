#include<iostream>
using namespace std;
void merge(int ar[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1],b[n2];//temp array
    for(int i=0;i<n1;i++)
    a[i]=ar[l+i];
    for(int i=0;i<n2;i++)
    b[i]=ar[mid+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            ar[k]=a[i];
            k++;
            i++;
        }
        else
        {
            ar[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        ar[k]=a[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        ar[k]=b[j];
        k++;
        j++;
    }
}
void mergeSort(int ar[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergeSort(ar,l,mid);
        mergeSort(ar,mid+1,r);
        merge(ar,l,mid,r);
    }
}
int main()
{
    int ar[]={5,4,3,2,1};
    mergeSort(ar,0,4);
    for(int i=0;i<5;i++)
    cout<<ar[i]<<" ";
}