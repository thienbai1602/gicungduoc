#include    <bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;

const int mxN = 1005;
const int pw = 1e6;
const int INF = 1e7;

struct adj
{
    int c, v, f;
};

int n, m;
vector<adj> edges[mxN];

int dijkstra(int flow)
{
    vector<int> dis(n);
    for(int i=0; i<n; i++) dis[i] = INF;
    dis[0] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 0});

    while(!pq.empty())
    {
        int u = pq.top().se, cdist = pq.top().fi;
        pq.pop();

        if (dis[u] != cdist) continue;

        for(auto [w, v, f] : edges[u])
        {
            if (dis[v] > dis[u] + w && f >= flow)
            {
                pq.push({dis[v] = dis[u] + w, v});
            }
        }
    }
    return dis[n - 1] == INF ? -1 : dis[n - 1];
}

void solve()
{
    cin >> n >> m;
    vector<int> flows;
    for(int i=0; i<m; i++)
    {
        int u, v, f, w;
        cin >> u >> v >> w >> f;
        --u, --v;
        flows.push_back(f);
        edges[u].push_back({w, v, f});
        edges[v].push_back({w, u, f});
    }

    ll ret = 0;
    for(int f : flows)
    {
        int tot_cost = dijkstra(f);
        if (tot_cost != -1)
        {
            ld nxt = (ld)((ld)f / (ld)tot_cost);
            ret = max(ret, (ll)(nxt * pw));
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    solve();
    return 0;
}
