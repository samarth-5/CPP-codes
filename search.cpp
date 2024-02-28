#include <iostream>
using namespace std;
int binarySearch(int ar[],int l,int h,int key)    // O(log(n))
{
    int mid=l+(h-l)/2;
    if(ar[mid]==key)
    return mid;
    else if(ar[mid]<key)
    binarySearch(ar,mid+1,h,key);
    else
    binarySearch(ar,l,mid-1,key);
}
int interpolationSearch(int ar[],int l,int h,int key)   // O(log(log(n))) 
{
    int mid=l+((key-ar[l])*(h-l)/(ar[h]-ar[l]));
    if(ar[mid]==key)
    return mid;
    else if(ar[mid]<key)
    binarySearch(ar,mid+1,h,key);
    else
    binarySearch(ar,0,mid-1,key);
}
int main()
{
    int ar[]={2,3,4,6,7,8,15};
    //int idx=interpolationSearch(ar,0,sizeof(ar)/sizeof(int),8);
    int idx=binarySearch(ar,0,sizeof(ar)/sizeof(int),8);
    cout<<idx;
}