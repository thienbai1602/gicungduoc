#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 166;
const ll INF = 1e15;

int n, m;
vector<ii> edges[mxN];

vector<ll> dij(int st)
{
    vector<ll> dist(n, INF);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(mp(0, st)); dist[st] = 0;

    while(!pq.empty())
    {
        ii nxt = pq.top(); pq.pop();
        ll u = nxt.se, cdist = nxt.fi;

        if (cdist != dist[u]) continue;

        for(auto [w, v] : edges[u])
        {
            if (dist[v] > dist[u] + w)
            {
                pq.push(mp(dist[v] = dist[u] + w, v));
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
        edges[u].pb(mp(w, v));
        edges[v].pb(mp(w, u));
    }

    ll ans = INF;
    for(int st=0; st<n; st++)
    {
        ll nxt = 0;
        vector<ll> dis = dij(st);
        for(int u=0; u<n; u++)
        {
            nxt += dis[u];
        }
        ans = min(ans, nxt);
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
