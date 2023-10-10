#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 266;
const ll INF = 1e10;

int n, m;
ii edges[mxN][mxN];
vector<int> path;
ll deg[mxN], s[mxN], del[mxN];

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        edges[u][v] = mp(c, i);
        edges[v][u] = mp(c, i);
        deg[u]++, deg[v]++;
    }

    for(int u=0; u<n; u++)
    {
        if (deg[u] & 1)
        {
            cout << -1;
            return;
        }
    }

    stack<int> st; st.push(0);
    fill(del, del + 1 + n, 0);
    while(!st.empty())
    {
        int u = st.top();
        bool flat = false;
        for(int v=0; v<n; v++)
        {
            if (u == v) continue;
            ll dist = edges[u][v].fi, ct = edges[u][v].se;
            if (!del[ct] && dist != INF)
            {
                st.push(v);
                del[ct] = 1;
                flat = true;
                break;
            }
        }

        if (!flat)
        {
            st.pop();
            path.pb(u);
        }
    }

    for(int i=1; i<sz(path); i++)
    {
        s[i] = s[i - 1] + edges[path[i - 1]][path[i]].fi;
    }

    if (s[sz(path) - 1] < 0 || sz(path) != m + 1)
    {
        cout << -1;
        return;
    }

    int mi = 1;
    for(int i=1; i<sz(path); i++)
    {
        if (s[mi] > s[i])
        {
            mi = i;
        }
    }

    vector<int> ret;
    for(int i=mi; i<sz(path); i++)
    {
        ret.pb(path[i]);
    }

    for(int i=1; i<=mi; i++)
    {
        ret.pb(path[i]);
    }

    for(int x : ret) cout << x + 1 << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
