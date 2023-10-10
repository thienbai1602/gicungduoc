#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

const ll INF = 1e18;
const int mxN = 166;

ll n, D, a[mxN], dist[mxN];
ii points[mxN];

ll kc(int x, int y)
{
    return abs(points[x].fi - points[y].fi) + abs(points[x].se - points[y].se);
}

void dij(int st)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    fill(dist, dist + n, INF);
    pq.push(mp(0, st)); dist[st] = 0;

    while(!pq.empty())
    {
        ii nxt = pq.top();
        pq.pop();

        ll u = nxt.se, cdist = nxt.fi;
        if (cdist != dist[u]) continue;

        for(int v=1; v<n; v++)
        {
            if (v == u) continue;
            if (dist[v] > dist[u] + kc(u, v) * D - a[u])
            {
                pq.push(mp(dist[v] = dist[u] + kc(u, v) * D - a[u], v));
            }
        }
    }

}

void solve()
{
    cin >> n >> D;
    a[0] = a[n - 1] = 0;
    for(int i=1; i<n-1; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<n; i++)
    {
        cin >> points[i].fi >> points[i].se;
    }

    dij(0);
    cout << dist[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
