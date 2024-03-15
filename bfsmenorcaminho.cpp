#include <bits/stdc++.h>
using namespace std;
const int inf = 1e6;
const int maximo = 2*1e3;
vector<int> g[maximo];


int bfs(int u, vector<int>& dist)
{
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for(int to:g[current])
        {
            if(dist[to] > dist[current]+1)
            {
                dist[to] = dist[current]+1;
                q.push(to);
            }
        }
    }
    int x = 0;
    for(auto e:dist) if(e > x) x = e;
    return x;
}
