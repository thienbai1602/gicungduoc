#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 55;

int n, m, ct;
bool vis[mxN];
stack<int> st;
int low[mxN], num[mxN], p[mxN];
vector<int> edges[mxN];

void be_nhanh(int u)
{
    while(st.top() != u)
    {
        vis[st.top()] = true;
        st.pop();
    }
    vis[u] = true;
    st.pop();
}

void tarjan(int u)
{
    st.push(u);
    ++ct; low[u] = num[u] = ct;
    for(int v : edges[u])
    {
        if (!vis[v])
        {
            if (num[v])
            {
                if (p[u] != v) low[u] = min(low[u], num[v]);
            } else
            {
                p[v] = u;
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (low[u] == num[u]) be_nhanh(u);
}

void new_graph()
{
    for(int i=0; i<n; i++) edges[i].clear();

    for(int v=0; v<n; v++)
    {
        if (num[v] > 1)
        {
            if (low[v] >= num[v])
            {
                int u = p[v];
                edges[u].push_back(v);
                edges[v].push_back(u);
            }
        }
    }
}

int dfs(int u)
{
    int ans = 1;
    vis[u] = true;
    for(int v : edges[u])
    {
        if (!vis[v])
        {
            ans += dfs(v);
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            p[i] = n + 1;
            ct = 0;
            tarjan(i);
        }
    }

    new_graph();

    ll ret = 0;
    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            int node = dfs(i);
            ret += (node - 1) * node / 2 - (node - 1);
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
