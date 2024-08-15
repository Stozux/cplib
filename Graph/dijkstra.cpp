#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll MXN = 1e5+5; 
const ll INF = LLONG_MAX;
int v,e;
vector<pll> adj[MXN];
vector<ll>parent(MXN,-1);
vector<ll> dist(MXN, INF);

void dijkstra(ll node)
{
    dist[node] = 0;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,node});
    while (!pq.empty())
    {
        auto [d,u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;
        for(auto [cost,v] : adj[u])
        {
            ll currD = dist[u] + cost;
            if(currD < dist[v])
            {
                dist[v] = currD;
                parent[v] = u;
                pq.push({currD,v});
            }
        }
    }
}