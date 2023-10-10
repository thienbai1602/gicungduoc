#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

const int mxM = 1e4 + 66;
const int mxN = 166;
const ll INF = 1e18;

int n, m;
ll w[mxM], x[mxM], y[mxM];
vector<ii> edges[mxN], adj[mxN];

ll dij(int k)
{
    for(int i=0; i<n; i++)
    {
        adj[i].clear();
    }

    for(int i=0; i<m; i++)
    {
        ll u = x[i], v = y[i], c = w[i];
        if (i == k) c *= 2;
        adj[u].pb(mp(c, v));
        adj[v].pb(mp(c, u));
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<ll> dis(n, INF);
    dis[0] = 0; pq.push(mp(0, 0));

    while(!pq.empty())
    {
        ii nxt = pq.top(); pq.pop();
        ll u = nxt.se, cdist = nxt.fi;

        if (cdist != dis[u]) continue;

        for(auto [w, v] : adj[u])
        {
            if (dis[v] > dis[u] + w)
            {
                pq.push(mp(dis[v] = dis[u] + w, v));
            }
        }
    }
    return dis[n - 1];
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> x[i] >> y[i] >> w[i];
        --x[i], --y[i];
        edges[x[i]].pb(mp(w[i], y[i]));
        edges[y[i]].pb(mp(w[i], x[i]));
    }

    ll ans = 0, st = dij(-1);
    for(int i=0; i<m; i++)
    {
        ans = max(ans, dij(i) - st);
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
