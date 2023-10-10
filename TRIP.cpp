#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

const ll INF = 1e18;
const int mxN = 166;
const int mxA = 1e4 + 66;

int n, m, tr[mxA];
ll cost[mxN][mxN], dist[mxN];

ll dij(int s, int t)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    fill(dist, dist + n, INF);
    pq.push(mp(0, s));
    dist[s] = 0;

    while(!pq.empty())
    {
        ii nxt = pq.top(); pq.pop();
        ll u = nxt.se, cdist = nxt.fi;

        if (cdist != dist[u]) continue;

        for(int v=0; v<n; v++)
        {
            if (u == v) continue;
            if (dist[v] > dist[u] + cost[u][v])
            {
                pq.push(mp(dist[v] = dist[u] + cost[u][v], v));
            }
        }
    }
    return dist[t];
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> tr[i];
        --tr[i];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> cost[i][j];
        }
    }

    ll ans = 0;
    for(int i=0; i<m-1; i++)
    {
        ans += dij(tr[i], tr[i + 1]);
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
