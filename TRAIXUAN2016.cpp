#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 105;

bool vis[mxN];
stack<int> st;
int n, m, cnt = 0;
int low[mxN], num[mxN], child[mxN], p[mxN];
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
    child[u] = 1;
    ++cnt, low[u] = cnt, num[u] = cnt;
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
                child[u] += child[v];
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

    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            cnt = 0;
            p[i] = n + 1;
            tarjan(i);
        }
    }

    ll ret = 0;
    for(int v=0; v<n; v++)
    {
        if (p[v] == n + 1) continue;
        if (low[v] >= num[v])
        {
            ret += child[v] * (n - child[v]);
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
