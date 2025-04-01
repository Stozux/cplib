#include <bits/stdc++.h>
using namespace std;
const int ALPHA = 26;


struct Node {
    int nxt[ALPHA] {};
    int subtree_cnt = 0;
};

using Trie = vector<Node>;



void add_word(string str, Trie& tr)
{
    int cur =0;

    for(auto ch:str)
    {
        if(tr[cur].nxt[ch-'a']==0)
        {
            int len = (int)tr.size();
            tr[cur].nxt[ch - 'a'] = len;
            tr.emplace_back();
        }

        tr[cur].subtree_cnt +=1;
        cur= tr[cur].nxt[ch -'a'];
    }
    tr[cur].subtree_cnt +=1;
}

int query_prefix(string str, Trie& tr)
{
    int cur = 0;

    for(auto ch:str)
    {
        if(tr[cur].nxt[ch-'a']==0) return 0;
        cur = tr[cur].nxt[ch -'a'];
    }
    return tr[cur].subtree_cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Trie tr(1); 
    int n,q;cin>>n>>q;
    string s;
    for(int i =0;i<n;i++)
    {
        cin >> s;
        add_word(s,tr);
    }
    while(q--)
    {
        string x;cin >> x;
        cout << query_prefix(x,tr) <<"\n";
    }
}