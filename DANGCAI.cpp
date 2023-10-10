#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

const int mxN = 166;
const ll INF = 1e18;

int n, m;
vector<ii> edges[mxN];

ll dij(int st)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<ll> dis(n, INF);
    dis[st] = 0; pq.push(mp(0, st));

    while(!pq.empty())
    {
        ii nxt = pq.top(); pq.pop();
        ll u = nxt.se, cdist = nxt.fi;

        if (cdist != dis[u]) continue;

        for(auto [w, v] : edges[u])
        {
            if (dis[v] > dis[u] + w)
            {
                pq.push(mp(dis[v] = dis[u] + w, v));
            }
        }
    }

    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        ans = max(ans, dis[i]);
    }
    return ans;
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        ll u, v, t;
        cin >> u >> v >> t;
        --u, --v;
        edges[u].pb(mp(t, v));
        edges[v].pb(mp(t, u));
    }

    ll city_hold = -1, max_dis = INF;
    for(int i=0; i<n; i++)
    {
        ll nxt = dij(i);
        if (nxt < max_dis)
        {
            max_dis = nxt;
            city_hold = i;
        }
    }
    cout << city_hold + 1 << " " << max_dis << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
