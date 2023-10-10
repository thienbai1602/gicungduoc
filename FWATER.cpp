#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 366;

struct edge
{
    ll u, v, w;

    edge(ll _u = 0, ll _v = 0, ll _w = 0)
    {
        u = _u, v = _v, w = _w;
    }

    bool operator < (edge x)
    {
        return w < x.w;
    }
};

int n;
ll p[mxN][mxN];
int par[mxN], sz[mxN];
vector<edge> edges;

int findp(int u)
{
    if (u == par[u]) return u;
    return par[u] = findp(par[u]);
}

bool Union(int a, int b)
{
    a = findp(a), b = findp(b);
    if (a == b) return 1;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    return 0;
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        p[n][i] = p[i][n] = x;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> p[i][j];
        }
    }

    ++n;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            edges.pb(edge(i, j, p[i][j]));
        }
    }

    for(int i=0; i<n; i++)
    {
        sz[i] = 1;
        par[i] = i;
    }

    sort(all(edges));

    ll ans = 0, cnt = 0;
    for(int i=0; i<sz(edges); i++)
    {
        bool f = Union(edges[i].u, edges[i].v);
        if (!f)
        {
            ++cnt;
            ans += edges[i].w;
        }

        if (cnt == n - 1) break;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
