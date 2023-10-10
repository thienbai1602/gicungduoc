#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
using namespace std;

const ll INF = 1e17;
const int mxN = 5e4 + 66;

int n, m, s, t;
ll dis[mxN], p[mxN];
vector<ii> edges[mxN];

void dij(int s)
{
    fill(dis, dis + n, INF);
    dis[s] = 0; p[s] = n + 1;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(mp(0, s));

    while(!pq.empty())
    {
        ii nxt = pq.top(); pq.pop();
        ll u = nxt.se, cdist = nxt.fi;

        if (cdist != dis[u]) continue;

        for(auto [w, v] : edges[u])
        {
            if (dis[v] > dis[u] + w)
            {
                p[v] = u;
                pq.push(mp(dis[v] = dis[u] + w, v));
            }
        }
    }
}

void tv(int u)
{
    cout << dis[u] << "\n";
    vector<ll> ret;
    while(u != n + 1)
    {
        ret.pb(u);
        u = p[u];
    }

    for(int i=sz(ret)-1; i>=0; i--)
    {
        cout << ret[i] + 1 << " ";
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
    }

    dij(s);
    if (dis[t] == INF)
    {
        cout << -1;
    } else
    {
        tv(t);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
