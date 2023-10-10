#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fi first
#define se second
using namespace std;

const int mxN = 1e5 + 66;

int n, Q;
int p[mxN], sz[mxN];
vector<pair<ll, pair<ll, ll>>> edges, queries;

int findp(int u)
{
    if (u != p[u]) return p[u] = findp(p[u]);
     else return u;
}

void Union(int a, int b)
{
    a = findp(a), b = findp(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
}

void solve()
{
    cin >> n >> Q;
    for(int i=0; i<n-1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.pb(mp(w, mp(u, v)));
    }

    for(int i=0; i<Q; i++)
    {
        ll v, k;
        cin >> k >> v;
        --v;
        queries.pb(mp(k, mp(v, i)));
    }

    for(int i=0; i<n; i++)
    {
        sz[i] = 1;
        p[i] = i;
    }

    sort(all(edges), greater<pair<ll, pair<ll, ll>>>());
    sort(all(queries), greater<pair<ll, pair<ll, ll>>>());

    int pos = 0;
    vector<int> ans(Q);
    for(int i=0; i<Q; i++)
    {
        while(pos < n && edges[pos].fi >= queries[i].fi)
        {
            ll u = edges[pos].se.fi, v = edges[pos].se.se;
            Union(u, v);
            ++pos;
        }

        ll id = queries[i].se.se, v = queries[i].se.fi;
        ans[id] = sz[findp(v)];
    }

    for(int i=0; i<Q; i++)
    {
        cout << ans[i] - 1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    solve();
    return 0;
}
