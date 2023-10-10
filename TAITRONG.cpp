#include    <bits/stdc++.h>
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e3 + 66;

int n, m, s, t;
vector<ii> edges[mxN];

bool check(int X)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<ll> dist(n + 1, INF);
    dist[s] = 0;
    pq.push(mp(0, s));

    while(!pq.empty())
    {
        int u = pq.top().se, cdist = pq.top().fi;
        pq.pop();
        if (cdist != dist[u]) continue;

        for(auto [z, v] : edges[u])
        {
            if (dist[v] > dist[u] + 1 && z >= X)
            {
                pq.push(mp(dist[v] = dist[u] + 1, v));
            }
        }
    }
    return dist[t] < INF;
}

int bs(int l, int r)
{
    int ans = -1;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (check(m))
        {
            ans = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> m >> s >> t;
    --s, --t;
    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges[u].pb(mp(w, v));
        edges[v].pb(mp(w, u));
    }
    cout << bs(1, 1e5);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
