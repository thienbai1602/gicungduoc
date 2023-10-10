#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 2e5 + 66;

int n, m;
vector<int> edges[mxN];
int p[mxN], sz[mxN], queries[mxN], ma = 1;

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
    ma = max(ma, sz[a]);
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        --a;
        queries[n - i - 1] = a;
    }

    for(int i=0; i<n; i++)
    {
        p[i] = i;
        sz[i] = 1;
    }

    vector<int> ans;
    vector<bool> activated(n, false);
    for(int i=0; i<n; i++)
    {
        int u = queries[i];
        activated[u] = true;

        for(int v : edges[u])
        {
            if (activated[v])
            {
                Union(u, v);
            }
        }
        if (ma == i + 1) ans.pb(1);
         else ans.pb(0);
    }

    for(int i=sz(ans)-1; i>=0; i--)
    {
        cout << (ans[i] ? "YES\n" : "NO\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    solve();
    return 0;
}
