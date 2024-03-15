#include <bits/stdc++.h>
using namespace std;
#define fIo ios::sync_with_stdio(false); cin.tie(NULL);



const int maximo = 1e5+10;
vector<int> g[maximo];
int n,m;

void bfs(vector<bool>& vis, int u)
{
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for(int to:g[current])
        {
            if(vis[to]== false)
            {
                vis[to] = true;
                q.push(to);
            }
        }
    }
}
