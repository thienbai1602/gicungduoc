#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

const ll INF = 1e18;
const int mxN = 5e3 + 66;

int n, m, s;
ll dist[mxN], f[mxN];
vector<ii> edges[mxN];

void dij(int st)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(mp(0, st)); memset(f, 0, sizeof(f));
    fill(dist, dist + n, INF);
    dist[st] = 0; f[st] = 1;

    while(!pq.empty())
    {
        ii nxt = pq.top(); pq.pop();
        ll u = nxt.se, cdist = nxt.fi;

        if (cdist != dist[u]) continue;

        for(auto [w, v] : edges[u])
        {
            if (dist[v] == dist[u] + w) f[v] += f[u];
            if (dist[v] > dist[u] + w)
            {
                pq.push(mp(dist[v] = dist[u] + w, v));
                f[v] = f[u];
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> s;
    --s;
    for(int i=0; i<m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges[u].pb(mp(w, v));
    }

    dij(s);

    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += (f[i] == 1);
    }
    cout << ans - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
