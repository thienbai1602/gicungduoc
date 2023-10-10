#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int mxN = 2e5 + 66;

int n;
ll dp[mxN];
vector<int> edges[mxN];

ll dfs(int u)
{
    ll ans = 0;
    for(int v : edges[u])
    {
        ans += dfs(v) + 1;
    }
    return dp[u] = ans;
}

void solve()
{
    cin >> n;
    for(int i=1; i<n; i++)
    {
        int par;
        cin >> par;
        par--;
        edges[par].pb(i);
    }

    memset(dp, 0, sizeof(dp));
    dfs(0);
    for(int i=0; i<n; i++)
    {
        cout << dp[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
