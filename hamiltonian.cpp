#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
class graph
{
    public:
    int n,m;
    unordered_map<int, vector<int>>adj;
    graph()
    {
        cout<<"Enter no. of nodes:";
        cin>>n;
        cout<<"Enter no. of edges:";
        cin>>m;
        int u,v;
        for(int i=0;i<m;i++)
        {
            cout<<"Enter the 1st node of edge:"<<i+1<<":";
            cin>>u;
            cout<<"Enter the 2nd node of edge:"<<i+1<<":";
            cin>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
};
bool dfs(int i,vector<int> &vis,vector<int> &path,graph g)
{
    vis[i]=1;
    path[i]=1;
    bool flag=1;
    for(auto it:g.adj[i])
    {
        if(!vis[it])
        {
            if(dfs(it,vis,path,g))
            return true;
        }
    }
    for(int j=1;j<=g.n;j++)
    {
        if(!path[j])
        flag=0;
    }
    path[i]=0;
    if(flag==1)
    return 1;
    else 
    return 0;
}
bool isHamil(graph g)
{
    vector<int>vis(g.n+1,0);
    vector<int> path(g.n+1,0);
    for(int i=1;i<g.n+1;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,vis,path,g))
            return true;
        }
    }
    return false;
}
int main()
{
    graph g;
    if(isHamil(g))
    cout<<"Hamil";
    else
    cout<<"No Hamil";
}