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
const int mxN = 1e2 + 66;

struct Edge
{
    int u, v, c;
    Edge(int _u = 0, int _v = 0, int  _c = 0)
    {
        u = _u, v = _v, c = _c;
    }

    bool operator < (Edge w)
    {
        return c < w.c;
    }
};

int n, m, sz[mxN], par[mxN];
vector<Edge> edges;
vector<int> adj;

int root(int u)
{
    if (u == par[u]) return u;
    return par[u] = root(par[u]);
}

ll mst(int k)
{
    ll ret = 0; adj.clear();
    for(int i=0; i<n; i++)
    {
        par[i] = i;
    }

    for(int i=0; i<m; i++)
    {
        if (i == k) continue;
        int u = edges[i].u, v = edges[i].v, w = edges[i].c;
        int a = root(u), b = root(v);
        if (a != b)
        {
            ret += w;
            adj.pb(i);
            if (sz[a] > sz[b]) swap(a, b);
            par[b] = a; sz[a] += sz[b];
        }
        if (sz(adj) == n-1) return ret;
    }
    return INF;
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        edges.pb(Edge(u, v, c));
    }

    sort(all(edges));
    ll ans1 = mst(m);
    ll ans2 = INF;
    vector<int> tp = adj;
    for(int &x : tp)
    {
        ans2 = min(ans2, mst(x));
    }
    cout << ans1 << " " << ans2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
