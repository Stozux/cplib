#include <bits/stdc++.h>
using namespace std;

const int maximo = 1e5+10;
vector<int> g[maximo];

bool dfs(int v, vector<bool>& d, vector<bool>& c)
{
    d[v] = true;
    for(int u:g[v])
    {
        if(!d[u])
        {
            c[u] = !c[v];
            if(!dfs(u, d, c)) return false;
        } else if(c[v] == c[u]) return false;
    }
    return true;
}

