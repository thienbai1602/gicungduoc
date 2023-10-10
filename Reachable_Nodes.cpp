#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 5e4 + 66;

bool vis[mxN];
int n, m, in[mxN];
bitset<mxN> reach[mxN];
vector<int> edges[mxN];

void dfs(int u)
{
    vis[u] = true;
    for(int v : edges[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
        reach[u] |= reach[v];
    }
    reach[u][u] = 1;
}

void solve()
{
    cin >> n >> m;
    memset(in, 0, sizeof(in));
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        in[v]++;
        edges[u].push_back(v);
    }

    queue<int> pq;
    for(int i=0; i<n; i++)
    {
        if (!in[i])
        {
            pq.push(i);
        }
    }

    memset(vis, false, sizeof(vis));
    while(!pq.empty())
    {
        int u = pq.front();
        pq.pop();
        dfs(u);
    }

    for(int i=0; i<n; i++)
    {
        cout << reach[i].count() << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
