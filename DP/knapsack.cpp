#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MXN = 1e3+5;
const int MXK = 1e5+4;
int dp[MXN][MXK];


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    vector<int> weights(n);
    vector<int> values(n);
    for(int i =1;i<=n;i++)
    {
        int cost = weights[i-1];
        int val = values[i-1];
        for(int j=0;j<=k;j++)
        {   
            if(j>=cost) dp[i][j] = max(dp[i-1][j],dp[i-1][j-cost]+val);
            else dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=k+2;j++) cout << dp[i][j] <<" ";
    //     cout <<"\n";
    // }
    cout << dp[n][k]<<"\n";
}