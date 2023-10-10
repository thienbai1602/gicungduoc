#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 166;
const ll INF = 1e15;

int n, m;
vector<ii> edges[mxN];

vector<ll> dijk(int st)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<ll> dist(n, INF);
    dist[st] = 0;
    pq.push(mp(0, st));
    while(!pq.empty())
    {
        ll u = pq.top().se;
        ll cdist = pq.top().fi;
        pq.pop();

        if (cdist != dist[u]) continue;

        for(int i=0; i<sz(edges[u]); i++)
        {
            int v = edges[u][i].se;
            ll dis = edges[u][i].fi;
            if (dis + cdist < dist[v])
            {
                dist[v] = dis + cdist;
                pq.push(mp(dist[v], v));
            }
        }
    }
    return dist;
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges[u].push_back(mp(w, v));
        edges[v].push_back(mp(w, u));
    }

    vector<ll> dist_1 = dijk(0);
    vector<ll> dist_n = dijk(n - 1);

    ll ret = INF;
    for(int u=0; u<n; u++)
    {
        for(int j=0; j<sz(edges[u]); j++)
        {
            int v = edges[u][j].se;
            ret = min(ret, dist_1[u] + dist_n[v]);
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("TICKET.INP", "r", stdin);
    freopen("TICKET.OUT", "w", stdout);
    solve();
    return 0;
}
