#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int n, K;
vector<int> edges[mxN];
ll dp[mxN], f[mxN], a[mxN];

void dfs(int u, int p)
{
    for(int v : edges[u])
    {
        if (v != p)
        {
            dfs(v, u);
            if (u != 0) dp[u] += dp[v] + f[v];
        }
    }
}

void solve()
{
    cin >> n >> K;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    for(int i=0; i<K; i++)
    {
        int u;
        cin >> u;
        ++f[--u];
    }

    memset(dp, 0, sizeof(dp));
    dfs(0, n + 1);

    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += ((dp[i] + a[i]) & 1);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("SOFTWARE.INP", "r", stdin);
    //freopen("SOFTWARE.OUT", "w", stdout);
    solve();
    return 0;
}


