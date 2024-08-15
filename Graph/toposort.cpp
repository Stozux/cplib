#include <bits/stdc++.h>
using namespace std;

int n,m;

void setEdge(vector<int> g[], int u, int v)
{
    g[u].push_back(v);
}


void bfs(vector<int> g[], vector<int>& indegree)
{
    vector<int> topo_order;
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0) pq.push(i);
    }
    while(!pq.empty())  
    {
        int u = pq.top();
        pq.pop();
        topo_order.push_back(u);
        for(int k:g[u])
        {
            if(--indegree[k] == 0)
            {
                pq.push(k);
            }
        }
    }
    if(topo_order.size() == n) 
    {
        for(auto x:topo_order) cout << x+1 << " "; 
        cout << "\n";
    } else cout << "Sandro fails.\n";
}
