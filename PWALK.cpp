#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mxN = 1066;

int n, Q;
ll dp[mxN];
vector<ii> edges[mxN];

void dfs(int u, int st, int ed)
{
    for(auto [w, v] : edges[u])
    {
        if (dp[v] == 0 && v != st)
        {
            dp[v] = dp[u] + w;
            dfs(v, st, ed);
        }
    }
}

void solve()
{
    cin >> n >> Q;
    for(int i=0; i<n-1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges[u].push_back(mp(w, v));
        edges[v].push_back(mp(w, u));
    }

    while(Q--)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        dfs(u, u, v);
        cout << dp[v] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
