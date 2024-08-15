    for(int k = 0;k<n;k++)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int d1 = adj[i][j];
                int d2 = adj[i][k] + adj[j][k];
                adj[i][j] = min(d1, d2);
            }
        }
    }