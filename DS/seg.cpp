#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int MXN = 2e5+10;
int vet[MXN];
int tree[4*MXN];
int n;
const int NEUTRO=0;

int join(int a,int b)
{
    return a+b;
}

void build(int l=0, int r=n-1,int node=0)
{
    if(l==r) tree[node] = vet[l];
    else 
    {
        int m = (l+r)/2;
        build(l,m, 2*node+1);
        build(m+1,r, 2*node+2); 
        tree[node] = join(tree[2*node+1],tree[2*node+2]);
    }
}


void update(int ind, int val, int node=0, int l=0, int r=n-1)
{
    if(l==r) tree[node] = val;
    else
    {
        int m = (l+r)/2;
        if(ind<=m) update(ind,val, 2*node+1, l,m);
        else if(ind > m) update(ind,val, 2*node+2,m+1,r);
        tree[node] = join(tree[2*node+1] ,tree[2*node+2]);
    }
}


int query(int ql, int qr, int node=0, int l=0,int r=n-1)
{
    if(ql>r or qr<l) return NEUTRO;
    else if(ql<=l and qr>=r) return tree[node];
    int m=(l+r)/2;
    return join(query(ql,qr,2*node+1,l,m),query(ql,qr,2*node+2, m+1,r)); 
}

void test_tree()
{
    for(int  i =0;i<4*n;i++) cout << tree[i]<<" ";
    cout <<"\n";
}


signed main()
{
    cin>>n; int q;cin>>q;
    for(int i =0;i<n;i++) cin >> vet[i];
    build();
    
}