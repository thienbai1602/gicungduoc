#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const ll INF = 1e17;
const int mxN = 4e4 + 66;

ll X, Y, P, n, m;
vector<int> edges[mxN];

vector<ll> dis(int st, ll cost)
{
    vector<ll> cdist(n, INF);
    cdist[st] = 0;
    queue<int> pq; pq.push(st);
    while(!pq.empty())
    {
        int u = pq.front();
        pq.pop();
        for(int v : edges[u])
        {
            if (cdist[v] == INF)
            {
                cdist[v] = cdist[u] + cost;
                pq.push(v);
            }
        }
    }
    return cdist;
}

void solve()
{
    cin >>  X >> Y >> P >> n >> m;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    vector<ll> dist_1 = dis(0, X);
    vector<ll> dist_2 = dis(1, Y);
    vector<ll> dist_n = dis(n - 1, P);

    ll ret = dist_1[n - 1] + dist_2[n - 1];
    for(int u=0; u<n; u++)
    {
        ret = min(ret, dist_1[u] + dist_2[u] + dist_n[u]);
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
}
