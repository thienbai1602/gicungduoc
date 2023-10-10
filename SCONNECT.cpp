#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 55;

int n, m, cnt = 0, low[N], num[N];
vector<bool> vis;
vector<int> edges[N];
stack<int> st;

void be_nhanh(int u)
{
    while(st.top() != u)
    {
        vis[st.top()] = true;
        cout << st.top() + 1 << " ";
        st.pop();
    }
    cout << u + 1;
    vis[u] = true;
    st.pop();
    cout << "\n";
}

void tarjan(int u)
{
    st.push(u); cnt++;
    num[u] = cnt, low[u] = cnt;

    for(int v : edges[u])
    {
        if (!vis[v])
        {
            if (num[v] > 0)
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

    vis.resize(n, false);

    for(int i=0; i<n; i++)
    {
        if (!vis[i]) tarjan(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
