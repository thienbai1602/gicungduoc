#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e5 + 66;
const ll INF = 1e18;

int n, m;
ll dis[mxN];
vector<ii> edges[mxN];

void dijk(int st)
{
    for(int i=0; i<n; i++)
    {
        dis[i] = INF;
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(mp(0, st)); dis[st] = 0;
    while(!pq.empty())
    {
        int u = pq.top().se;
        ll cdist = pq.top().fi;
        pq.pop();

        if (cdist != dis[u]) continue;
        for(auto [w, v] : edges[u])
        {
            if (cdist + w < dis[v])
            {
                pq.push(mp(dis[v] = cdist + w, v));
            }
        }
    }
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
    }
    dijk(0);
    for(int i=0; i<n; i++)
    {
        cout << dis[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
