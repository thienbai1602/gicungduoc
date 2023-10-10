#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;

const int mxN = 166;
const ll INF = 1e18;

int n, m;
vector<ii> edges[mxN];
ll ans[mxN][mxN], dist[mxN][mxN], p[mxN][mxN], c[3];


void dij(int node, int st)
{
    for(int u=0; u<n; u++)
    {
        dist[node][u] = INF;
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(mp(0, st));
    dist[node][st] = 0;
    p[node][st] = n + 1;

    while(!pq.empty())
    {
        ii nxt = pq.top(); pq.pop();
        ll u = nxt.se, cdist = nxt.fi;

        if (cdist != dist[node][u]) continue;

        for(auto [w, v] : edges[u])
        {
            if (dist[node][v] > dist[node][u] + w)
            {
                p[node][v] = u;
                pq.push(mp(dist[node][v] = dist[node][u] + w, v));
            }
        }
    }
}

ll tv(int u)
{
    ll ct = 0;
    while(u != n + 1)
    {
        int v = p[n + 1][u];
        ans[u][v] = 1;
        ans[v][u] = 1;
        u = v;
        ct++;
    }
    return ct;
}

void recur(int pos)
{
    dij(n + 1, pos);
    memset(ans, 0, sizeof(ans));

    ll cnt = 0;
    for(int i=0; i<3; i++)
    {
        cnt += tv(c[i]);
    }

    cout << cnt - 3 << "\n";
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if (ans[i][j])
            {
                cout << i + 1 << " " << j + 1 << "\n";
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
        edges[v].pb(mp(w, u));
    }
    cin >> c[0] >> c[1] >> c[2];

    for(int i=0; i<3; i++)
    {
        --c[i];
    }

    for(int i=0; i<n; i++)
    {
        dij(i, i);
    }

    ll ans = INF, pos = -1;
    for(int i=0; i<n; i++)
    {
        ll tp = dist[i][c[0]] + dist[i][c[1]] + dist[i][c[2]];
        if (tp < ans)
        {
            ans = tp;
            pos = i;
        }
    }

    if (pos == -1)
    {
        cout << 0;
    } else
    {
        cout << ans << "\n";
        recur(pos);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
