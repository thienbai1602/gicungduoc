#include    <bits/stdc++.h>
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e3 + 66;

int n, m, K;
vector<bool> vis;
vector<int> edges[mxN];

void dfs(int u)
{
    vis[u] = true;
    for(int v : edges[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

void solve()
{
    cin >> n >> m >> K;
    ll pMin = INF;
    for(int i=0; i<K; i++)
    {
        ll x;
        cin >> x;
        pMin = min(pMin, x);
    }

    for(int i=0; i<m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        --u, --v;
        if (t >= pMin)
        {
            edges[u].pb(v);
            edges[v].pb(u);
        }
    }

    int cnt = 0;
    vis.assign(n, false);
    for(int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            ++cnt;
        }
    }
    cout << cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

