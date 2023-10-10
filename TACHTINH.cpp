#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;
const ll INF = 1e18;

int n;
vector<int> edges[mxN];
ll dp[mxN], p[mxN], a[mxN], S = 0;

ll dfs(int u)
{
    for(int v : edges[u])
    {
        if (p[v] == -1)
        {
            p[v] = u;
            dp[u] += dfs(v);
        }
    }
    return dp[u] += a[u];
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        S += a[i];
    }

    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    p[0] = n + 1;
    memset(p, -1, sizeof(p));
    dfs(0);

    ll ret = INF;
    for(int u=0; u<n; u++)
    {
        for(int v : edges[u])
        {
            ret = min(ret, abs(S - 2 * dp[v]));
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
