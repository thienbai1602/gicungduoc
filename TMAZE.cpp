#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

const ll INF = 1e18;
const int mxN = 1e5 + 66;

ll dist[mxN];
int n, m, s, t;
vector<ii> edges[mxN];

void dij(int s, int t)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    fill(dist, dist + n, INF);
    pq.push(mp(18, s));
    dist[s] = 18;

    while(!pq.empty())
    {
        ii nxt = pq.top(); pq.pop();
        ll u = nxt.se, cdist = nxt.fi;

        if (cdist != dist[u]) continue;

        for(auto [w, v] : edges[u])
        {
            if (dist[v] > max(w, dist[u]))
            {
                pq.push(mp(dist[v] = max(w, dist[u]), v));
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> s >> t;
    --s, --t;
    for(int i=0; i<m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges[u].pb(mp(w, v));
        edges[v].pb(mp(w, u));
    }

    dij(s, t);
    cout << (dist[t] == INF ? -1 : dist[t]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
