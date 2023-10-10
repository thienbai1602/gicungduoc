#include    <bits/stdc++.h>
#define ll long long
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

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

ll n, m, K, dis[mxN];
vector<int> edges[mxN];

void dij(int st)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    fill(dis, dis + n + 1, INF);
    pq.push(mp(0, 0));
    dis[st] = 0;

    while(!pq.empty())
    {
        int u = pq.top().se;
        ll cdist = pq.top().fi;
        pq.pop();

        if (cdist != dis[u]) continue;

        for(int v : edges[u])
        {
            if (dis[v] > cdist + 1)
            {
                pq.push(mp(dis[v] = cdist + 1, v));
            }
        }
    }
}

bool sf(ll X)
{
    ll S = 0;
    for(int u=1; u<n; u++)
    {
        S += X / dis[u];
        if (S >= K) return true;
    }
    return false;
}

ll bs(ll l, ll r)
{
    ll ans = -1;
    while(l <= r)
    {
        ll m = l + (r - l) / 2;
        if (sf(m))
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> m >> K;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dij(0);
    cout << bs(1, 2e18);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
