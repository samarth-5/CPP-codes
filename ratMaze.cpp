#include <iostream>
using namespace std;
bool isSafe(int **ar,int x,int y,int n)
{
    if(x<n && y<n && ar[x][y]==1)
    return true;
    return false;
}
bool ratInMaze(int **ar,int x,int y,int n,int **soln)
{
    if(x==n-1 && y==n-1)
    {
        soln[x][y]=1;
        return true;
    }
    if(isSafe(ar,x,y,n))
    {
        soln[x][y]=1;
        if(ratInMaze(ar,x+1,y,n,soln))//right
        return true;
        if(ratInMaze(ar,x,y+1,n,soln))//downward
        return true;
        soln[x][y]=0;//backtracking
        return false;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int **ar=new int*[n];
    for(int i=0;i<n;i++)
    {
        ar[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>ar[i][j];
    }
    int **soln=new int*[n];
    for(int i=0;i<n;i++)
    {
        soln[i]=new int[n];
        for(int j=0;j<n;j++)
        soln[i][j]=0;
    }
    cout<<"-----------------\n";
    if(ratInMaze(ar,0,0,n,soln))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<soln[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}