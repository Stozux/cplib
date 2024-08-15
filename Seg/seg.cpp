#include <bits/stdc++.h>
using namespace std;

const int MXN = 10;
int vet[MXN];
int tree[4*MXN];
int n;

void build(int l=0, int r=n-1,int node=0)
{
    if(l==r) tree[node] = vet[l];
    else 
    {
        int m = (l+r)/2;
        build(l,m, 2*node+1);
        build(m+1,r, 2*node+2); 
        tree[node] = tree[2*node+1] + tree[2*node+2];
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
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
}


int query(int ql, int qr, int node=0, int l=0,int r=n-1)
{
    if(ql>r or qr<l) return 0;
    else if(ql<=l and qr>=r) return tree[node];
    int m=(l+r)/2;
    return query(ql,qr,2*node+1,l,m) + query(ql,qr,2*node+2, m+1,r); 
}

int main()
{
    n=6;
    vet[0] = 1;
    vet[1] = 2;
    vet[2] = 4;
    vet[3] = 3;
    vet[4] = 5;
    vet[5] = 10;
    build();
    for(int i =0;i<15;i++) cout << tree[i]<<" ";
    cout <<"\n";
    update(3,7);
    for(int i =0;i<15;i++) cout << tree[i]<<" ";
    cout <<"\n";
    cout << query(2,4)<<"\n";
}