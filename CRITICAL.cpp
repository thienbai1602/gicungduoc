#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 2e4 + 55;

int n, m, ct = 0, sz = 0;
bool vis[mxN];
stack<int> st;
int low[mxN], num[mxN], tp[mxN], khop[mxN], child[mxN], p[mxN], dfs[mxN];
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
    tp[u] = sz;
    st.push(u); dfs[u] = 1;
    ++ct, low[u] = num[u] = ct;
    for(int v : edges[u])
    {
        if (!vis[v])
        {
            if (num[v])
            {
                if (p[u] != v) low[u] = min(low[u], num[v]);
            }
            else
            {
                p[v] = u;
                tarjan(v);
                child[u]++;
                dfs[u] += dfs[v];
                low[u] = min(low[u], low[v]);
            }
        }
    }

    if (low[u] == num[u]) be_nhanh(u);
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

    memset(p, -1, sizeof(p));
    memset(vis, false, sizeof(vis));
    memset(child, 0, sizeof(child));
    for(int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            ct = 0, sz = i;
            p[i] = n + 1;
            tarjan(i);
        }
    }

    memset(khop, 0, sizeof(khop));
    for(int v=0; v<n; v++)
    {
        if (num[v] > 1)
        {
            int u = p[v];
            if (low[v] >= num[u])
            {
                //cout << u + 1 << " " << v + 1 << "\n";
                if (num[u] == 1 && child[u] < 2)
                {
                    khop[u] = 0;
                } else
                {
                    khop[u] = 1;
                }
            }
        }
    }

    ll ret = 0;
    for(int u=0; u<n; u++)
    {
        if (khop[u])
        {
            ll nxt = 0, s = 0;
            for(int v : edges[u])
            {
                if (p[v] == u && low[v] >= num[u])
                {
                    nxt += dfs[v];
                    s += (dfs[tp[u]] - 1 - dfs[v]) * dfs[v];
                }
            }
            s += (dfs[tp[u]] - nxt - 1) * nxt;
            ret += s / 2;
        }
    }
    cout << fixed << setprecision(2) << ((long double)ret / (long double)n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
