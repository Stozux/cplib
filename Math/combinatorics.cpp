#include <bits/stdc++.h>
#include <ios>
#include <iostream>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int MXN = 1e6+1; 

ll fact[MXN], invfact[MXN];

long long fast_exp(long long a, long long e = MOD-2) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= MXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invfact[MXN] = fast_exp(fact[MXN]);
    for (int i = MXN; i > 0; i--) {
        invfact[i - 1] = invfact[i] * i % MOD;
    }
}

long long comb_mod(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;cin>>q;
    init(); 
    while (q--) {
        ll x,y;cin>>x>>y;
        cout << comb_mod(x+1, y+1) <<"\n";
    }

}
