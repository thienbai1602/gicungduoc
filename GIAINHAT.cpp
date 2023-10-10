#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e4 + 55;

int n, m, cnt = 0, ct = 0;
bool vis[N];
stack<int> st;
int low[N], num[N], sc[N], x[N], y[N], dai_dien[N];
vector<int> edges[N];

void be_nhanh(int  u)
{
    ct++;
    while(st.top() != u)
    {
        vis[st.top()] = true;
        sc[st.top()] = ct;
        st.pop();
    }
    sc[u] = ct;
    st.pop();
    vis[u] = true;
    dai_dien[ct] = u;
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
        cin >> x[i] >> y[i];
        --x[i], --y[i];
        edges[x[i]].push_back(y[i]);
    }

    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            tarjan(i);
        }
    }

    for(int i=0; i<m; i++)
    {
        if (sc[x[i]] != sc[y[i]]) dai_dien[sc[x[i]]] = 0;
    }

    int ans = 0;
    for(int i=1; i<=ct; i++)
    {
        if (dai_dien[i] > 0 && sc[0] != i) ans++;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
