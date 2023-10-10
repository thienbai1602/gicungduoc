#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;

const int mxN = 1e5 + 66;
const ll INF = 1e18;

int n, m;
vector<ii> edges[mxN], adj[mxN];

vector<ll> min_cost(int st, vector<ii> edges[])
{
    vector<ll> dis(n, INF);
    dis[st] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, st});
    while(!pq.empty())
    {
        int u = pq.top().se;
        ll cdist = pq.top().fi;
        pq.pop();

        if (dis[u] != cdist) continue;

        for(auto [w, v] : edges[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    vector<ll> cost_from_1 = min_cost(0, edges);
    vector<ll> cost_from_n = min_cost(n - 1, adj);

    ll ret = INF;
    for(int u=0; u<n; u++)
    {
        for(auto [w, v] : edges[u])
        {
            ret = min(ret, cost_from_1[u] + cost_from_n[v] + w / 2);
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
