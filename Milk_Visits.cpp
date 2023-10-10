#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int mxN = 1e5 + 66;

string S;
int n, Q, ct = 0, cnt[mxN];
vector<int> edges[mxN];

void dfs(int u, char c, int r)
{
    cnt[u] = r;
    for(int v : edges[u])
    {
        if (cnt[v] == -1)
        {
            dfs(v, S[v], (S[v] == c ? cnt[u] : ++ct));
        }
    }
}

void solve()
{
    cin >> n >> Q >> S;
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    memset(cnt, -1, sizeof(cnt));
    dfs(0, S[0], 0);

    while(Q--)
    {
        char c;
        int u, v;
        cin >> u >> v >> c;
        --u, --v;
        if (cnt[u] == cnt[v] && S[u] != c) cout << 0;
         else cout << 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    solve();
    return 0;
}
