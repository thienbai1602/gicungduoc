#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int mxA = 21;
const ll INF = 1e18;
const int mxN = 1e4 + 66;

int n;
ll dp[mxN][mxA + 1];
vector<int> ans, edges[mxN];

void dfs(int u, int p)
{
    for(int col=1; col<=min(n, mxA); col++)
    {
        dp[u][col] = col;
    }

    for(int v : edges[u])
    {
        if (v != p)
        {
            dfs(v, u);
            for(int cur_col=1; cur_col<=min(n, mxA); cur_col++)
            {
                int id = -1;
                for(int prev_col=1; prev_col<=min(n, mxA); prev_col++)
                {
                    if (cur_col == prev_col) continue;
                    if (id == -1 || (dp[v][id] > dp[v][prev_col])) id = prev_col;
                }
                dp[u][cur_col] += dp[v][id];
            }
        }
    }
}

void trace(int u, int p, int c)
{
    ans[u] = c;
    for(int v : edges[u])
    {
        if (v != p)
        {
            int id = -1;
            for(int col=1; col<=min(n, mxA); col++)
            {
                if (col == c) continue;
                if (id == -1 || dp[v][id] > dp[v][col]) id = col;
            }
            trace(v, u, id);
        }
    }
}

void solve()
{
    cin >> n;
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    ans.resize(n);
    dfs(0, n + 1);

    ll c = -1;
    for(int col=1; col<=min(n, mxA); col++)
    {
        if (c == -1 || dp[0][col] < dp[0][c]) c = col;
    }
    trace(0, n + 1, c);

    cout << dp[0][c] << "\n";
    for(int i=0; i<n; i++)
    {
        cout << ans[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
