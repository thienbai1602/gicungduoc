#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int n, K, col[mxN];
ll dp[mxN][4];
vector<int> edges[mxN];

void dfs(int u, int p)
{
    if (col[u] == -1)
    {
        for(int c=1; c<4; c++)
        {
            dp[u][c] = 1;
        }
    } else
    {
        for(int c=1; c<4; c++)
        {
            if (c == col[u]) dp[u][c] = 1;
             else dp[u][c] = 0;
        }
    }

    vector<ll> S(4, 0);
    for(int v : edges[u])
    {
        if (v != p)
        {
            dfs(v, u);
            ll x = dp[v][1], y = dp[v][2], z = dp[v][3];
            dp[u][1] = ((dp[u][1] % MOD) * (y + z) % MOD) % MOD;
            dp[u][2] = ((dp[u][2] % MOD) * (x + z) % MOD) % MOD;
            dp[u][3] = ((dp[u][3] % MOD) * (y + x) % MOD) % MOD;

        }
    }
}

void solve()
{
    cin >> n >> K;
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    memset(col, -1, sizeof(col));
    for(int i=0; i<K; i++)
    {
        int u, c;
        cin >> u >> c;
        --u;
        col[u] = c;
    }

    dfs(0, n + 1);
    cout << (dp[0][1] + dp[0][2] + dp[0][3]) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    solve();
    return 0;
}
