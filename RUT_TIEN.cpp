#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

const ll INF = 1e18;
const int mxN = 1e5 + 66;

struct edge
{
    ll v, w, type;

    edge(ll _v = 0, ll _w = 0, ll _type = 0)
    {
        v = _v, w = _w, type = _type;
    }
};

struct state
{
    ll w, u, type, money;

    state(ll _w = 0, ll _u = 0, ll _type = 0, ll _money = 0)
    {
        w = _w, u = _u, type = _type, money = _money;
    }

    bool operator < (const state x) const
    {
        return w < x.w;
    }
};

ll n, m, K;
vector<edge> edges[mxN];
ll c[mxN], d[mxN], dis[mxN][2];

bool dij(int st, ll X)
{
    for(int i=0; i<n; i++)
    {
        for(int tp=0; tp<2; tp++)
        {
            dis[i][tp] = INF;
        }
    }

    priority_queue<state, vector<state>> pq;
    pq.push(state(0, st, 0, K));
    pq.push(state(0, st, 1, K));
    dis[0][0] = dis[0][1] = 0;

    while(!pq.empty())
    {
        state nxt = pq.top();
        pq.pop();

        ll u = nxt.u, cdist = nxt.w, cur_type = nxt.type, cur_money = nxt.money;
        if (cdist != dis[u][cur_type]) continue;

        for(auto [v, w, tp] : edges[u])
        {
            for(int md=0; md<=10; md++)
            {
                ll reality = min(cur_money + md * 100, K);
                if (reality >= w + (tp != cur_type) + md)
                {
                    if (dis[v][tp] > dis[u][cur_type] + (tp != cur_type) + w + md)
                    {
                        pq.push(state(dis[v][tp] = dis[u][cur_type] + (tp != cur_type) + w + md, v, tp, reality - w - md - (tp != cur_type)));
                    }
                    break;
                }
            }
        }
    }
    return (dis[n - 1][0] <= X || dis[n - 1][1] <= X);
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v >> c[i] >> d[i];
        --u, --v;
        edges[u].pb(edge(v, c[i], 0));
        edges[u].pb(edge(v, d[i], 1));
        edges[v].pb(edge(u, c[i], 0));
        edges[v].pb(edge(u, d[i], 1));
    }
    cin >> K;

    ll l = 0, r = 1e8, ans = -1;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (dij(0, m))
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
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
