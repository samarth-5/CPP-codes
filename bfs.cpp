#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class bfs
{
public:
    vector<int> bfsGraph(int n, vector<int> graph[])
    {
        int vis[n];
        for (int i = 0; i < n; i++)
        vis[i] = 0;
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for (auto i : graph[node])
            {
                if (!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        return bfs;
    }
    void dfs(int n, vector<int> graph[],int vis[],vector<int>&list,int curr)
    {
        list.push_back(curr);
        vis[curr]=1;
        for(auto i  :graph[curr])
        {
            if(!vis[i])
            dfs(n,graph,vis,list,i);
        }
    }
};

int main()
{
    int n = 7;
    vector<int> graph[n];
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(0);
    graph[1].push_back(3);
    graph[2].push_back(0);
    graph[2].push_back(4);
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    graph[4].push_back(2);
    graph[4].push_back(3);
    graph[4].push_back(5);
    graph[5].push_back(3);
    graph[5].push_back(4);
    graph[5].push_back(6);
    graph[6].push_back(5);
    bfs obj;
    vector<int> list = obj.bfsGraph(n, graph);
    //for (int i = 0; i < n; i++)
    //cout << list[i] << " ";
    int vis[n]={0};
    vector<int>dfsList;
    obj.dfs(n,graph,vis,dfsList,0);
    for (int i = 0; i < n; i++)
    cout << dfsList[i] <<" ";
}