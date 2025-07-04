using ll = long long;
const int MXN =510; 
const ll INF = 1e15;
ll adj[MXN][MXN];
int n,m,q;

void floyd_init()
{
    for(int i = 0;i<MXN;i++)
    {
        for(int j =0;j<MXN;j++)
        {
            if(i == j)
            {
                adj[i][j] = 0;
            }else adj[i][j] = INF;
        }
    }
}

void floyd()
{
    for(int k = 0;k<n;k++)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ll d1 = adj[i][j];
                ll d2 = adj[i][k] + adj[j][k];
                adj[i][j] = min(d1, d2);
            }
        }
    }
}
