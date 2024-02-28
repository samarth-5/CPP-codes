#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class prim
{
    public:
    int spanningTree(int n,vector<vector<int>>graph[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(n,0);
        //{wt,node}
        pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first; 
            if(vis[node]==1)
            continue;
            vis[node]=1;
            sum+=wt;
            for(auto itr : graph[node])
            {
                int neigh=itr[0];
                int edW=itr[1];
                if(!vis[neigh])
                {
                    pq.push({edW,neigh});
                }
            }
        }
        return sum;
    }
};