#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 55;

int n, m, cnt = 0, ct = 0;
bool vis[mxN];
stack<int> st;
int num[mxN], low[mxN], kingdom[mxN];
vector<int> edges[mxN];

void be_nhanh(int u)
{
    ct++;
    while(st.top() != u)
    {
        vis[st.top()] = true;
        kingdom[st.top()] = ct;
        st.pop();
    }
    kingdom[u] = ct;
    st.pop();
    vis[u] = true;
}

void tarjan(int u)
{
    st.push(u);
    low[u] = num[u] = ++cnt;
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
    }

    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            tarjan(i);
        }
    }

    cout << ct << "\n";
    for(int i=0; i<n; i++)
    {
        cout << kingdom[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
