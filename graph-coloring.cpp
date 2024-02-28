#include <iostream>
#include <vector>
using namespace std;
bool CHECK(int v, vector<int> graph[], vector<int>& color, int c) 
{
    for (int u : graph[v]) 
    {
        if (color[u] == c)
        return false;
    }
    return true;
}
bool Coloring(vector<int> graph[], int M, vector<int>& color, int v,int N) 
{
    if (v == N)
    return true;
    for (int c = 1; c <= M; ++c) 
    {
        if (CHECK(v, graph, color, c)) 
        {
            color[v] = c;
            if (Coloring(graph, M, color, v + 1,N))
            return true;
            color[v] = 0;
        }
    }
    return false;
}
bool Color(vector<int>graph[], int M, int N) 
{
    vector<int> color(N, 0);
    return Coloring(graph, M, color, 0,N);
}
int main() 
{
    int N, M;
    cout<<"ENTER THE VALUE OF N AND M\n";
    cin >> N >> M;
    vector<int> graph[N];
    for (int i = 0; i < N; ++i) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if (Color(graph, M,N))
    cout << "1\n";
    else
    cout << "0\n";
    return 0;
}