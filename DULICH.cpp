#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 3e5 + 55;

int n, m, ct = 0, sz = 0;
stack<int> st;
bool vis[mxN];
int low[mxN], num[mxN], sl[mxN], x[mxN], y[mxN], p[mxN], d1[mxN], d2[mxN], sc[mxN];
vector<int> edges[mxN], adj[mxN];

void be_nhanh(int u)
{
    sc[u] = u, sl[u] = 1;
    int v = st.top();
    while(u != v)
    {
        sc[v] = u;
        vis[v] = true;
        st.pop();
        v = st.top();
        sl[u]++;
    }

    vis[u] = true;
    st.pop();
}

void tarjan(int u)
{
    st.push(u);
    ct++, low[u] = ct, num[u] = ct;
    for(int v : edges[u])
    {
        if (!vis[v])
        {
            if (num[v])
            {
                low[u] = min(low[u], num[v]);
            } else
            {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }

    if (num[u] == low[u]) be_nhanh(u);
}

void nen_G()
{
    for(int i=0; i<n; i++) edges[i].clear();

    int canh = 0;
    for(int i=0; i<m; i++)
    {
        if (sc[x[i]] != sc[y[i]])
        {
            int u = sc[x[i]], v = sc[y[i]];
            x[canh] = u, y[canh] = v;
            canh++;
        }
    }

    m = canh;
    for(int i=0; i<m; i++)
    {
        edges[x[i]].push_back(y[i]);
        adj[x[i]].push_back(1);
        edges[y[i]].push_back(x[i]);
        adj[y[i]].push_back(2);
    }
}

void dfs1(int u)
{
    for(int i=0; i<(int)edges[u].size(); i++)
    {
        if (adj[u][i] == 1)
        {
            int v = edges[u][i];
            if (p[v] == -1)
            {
                p[v] = u;
                dfs1(v);
            }
            if (d1[v] != 0) d1[u] = max(d1[u], sl[u] + d1[v]);
        }
    }
}

void dfs2(int u)
{
    for(int i=0; i<(int)edges[u].size(); i++)
    {
        if (adj[u][i] == 2)
        {
            int v = edges[u][i];
            if (p[v] == -1)
            {
                p[v] = u;
                dfs2(v);
            }
            if (d2[v] != 0) d2[u] = max(d2[u], sl[u] + d2[v]);
        }
    }
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> x[i] >> y[i];
        edges[--x[i]].push_back(--y[i]);
    }

    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            tarjan(i);
        }
    }

    nen_G();

    memset(d1, 0, sizeof(d1));
    memset(p, -1, sizeof(p));
    d1[0] = sl[0];
    for(int i=1; i<n; i++)
    {
        if (p[sc[i]] == -1)
        {
            p[sc[i]] = n + 1;
            dfs1(sc[i]);
        }
    }

    memset(d2, 0, sizeof(d2));
    memset(p, -1, sizeof(p));
    d2[0] = sl[0];
    for(int i=1; i<n; i++)
    {
        if (p[sc[i]] == -1)
        {
            p[sc[i]] = n + 1;
            dfs2(sc[i]);
        }
    }

    for(int i=0; i<n; i++)
    {
        //cout << dai_dien[sc[i]] << " " << sc[i] << "\n";
        //cout << d1[dai_dien[sc[i]]]  << " " << dai_dien[sc[i]] << "\n";
        //cout << d2[i] << " ";
    }

    int ret = sl[0];
    for(int i=0; i<m; i++)
    {
        if (d1[x[i]] != 0 && d2[y[i]] != 0)
            ret = max(ret, d2[y[i]] + d1[x[i]] - sl[0]);
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
