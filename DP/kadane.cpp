#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<int> v(n);
    for(int i =0;i<n;i++) cin>>v[i];
    int ans = v[0], ans_l = 0, ans_r = 0;
    int sum = 0, minus_pos = -1;
    for (int r = 0; r < n; ++r) {
        sum += v[r];
        if (sum > ans) {
            ans = sum;
            ans_l = minus_pos + 1;
            ans_r = r;
        }
        if (sum < 0) {
            sum = 0;
            minus_pos = r;
        }
    }
    cout << ans <<"\n";
}
