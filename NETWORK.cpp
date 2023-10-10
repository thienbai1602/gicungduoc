#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int mxN = 1e4 + 66;

stack<int> st;
bool vis[mxN];
vector<int> edges[mxN];
int n, m, cnt = 0, num[mxN], low[mxN], p[mxN];

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
    num[u] = low[u] = ++cnt;
    for(int v : edges[u])
    {
        if (!vis[v])
        {
            if (num[v] > 0)
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

void solve()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    memset(vis, false, sizeof(vis));
    memset(p, -1, sizeof(p));
    tarjan(0);

    ll ans = 0;
    for(int v=0; v<n; v++)
    {
        if (p[v] == -1) continue;
        if (num[v] > 1 && low[v] >= num[v])
        {
            ++ans;
        }
    }
    cout << m - ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
