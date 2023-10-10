/*#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 55;

int n, m, cnt = 0, ct = 0;
stack<int> st;
bool vis[mxN];
ll coins[mxN], dai_dien[mxN], tot_coin[mxN], x[2 * mxN], y[2 * mxN], low[mxN], num[mxN], sc[mxN], dp[mxN];
vector<int> edges[mxN];

void be_nhanh(int u)
{
    ct++;
    while(st.top() != u)
    {
        vis[st.top()] = true;
        sc[st.top()] = ct;
        tot_coin[ct] += coins[st.top()];
        st.pop();
    }

    dai_dien[ct] = u;
    tot_coin[ct] += coins[u];
    sc[u] = ct;
    vis[u] = true;
    st.pop();
}

void tarjan(int u)
{
    st.push(u);
    low[u] = num[u] = ++cnt;
    for(int v : edges[u])
    {
        if (!vis[v])
        {
            if (num[v] > 0)
            {
                low[u] = min(low[u],  num[v]);
            } else
            {
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

    for(int i=0; i<m; i++)
    {
        if (sc[x[i]] != sc[y[i]])
        {
            edges[dai_dien[sc[x[i]]]].push_back(dai_dien[sc[y[i]]]);
        }
    }
}

ll dfs(int u)
{
    vis[u] = true;
    dp[u] = tot_coin[sc[u]];
    ll mx = 0;
    for(int v : edges[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
        mx = max(dp[v], mx);
    }
    return dp[u] += mx;
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> coins[i];
    }

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

    new_graph();
    memset(vis, false, sizeof(vis));
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    ll ret = 0;
    for(int i=0; i<n; i++)
    {
        ret = max(ret, dp[i]);
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}*/
#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 55;

int n, m, cnt, scc = 0;
ll coin[mxN];
bool vis[mxN];
stack<int> st;
vector<int> revTopo;
vector<int> edges[mxN], g[mxN];
ll low[mxN], num[mxN], tp[mxN], dp[mxN], tot_coins[mxN];

void be_nhanh(int u)
{
    tot_coins[scc] = coin[u];
    while(st.top() != u)
    {
        int v = st.top();
        vis[v] = true;
        tp[v] = scc;
        tot_coins[scc] += coin[v];
        st.pop();
    }
    tp[u] = scc;
    vis[u] = true;
    st.pop();
    ++scc;
}

void tarjan(int u)
{
    st.push(u);
    low[u] = num[u] = ++cnt;
    for(int v : edges[u])
    {
        if (!vis[v])
        {
            if (num[v]) low[u] = min(low[u], num[v]);
             else
             {
                 tarjan(v);
                 low[u] = min(low[u], low[v]);
             }
        }
    }
    if (low[u] == num[u]) be_nhanh(u);
}

void new_graph()
{
    for(int u=0; u<n; u++)
    {
        for(int v : edges[u])
        {
            if (tp[u] != tp[v])
            {
                g[tp[u]].push_back(tp[v]);
            }
        }
    }
}

void dfs(int u)
{
    vis[u] = true;
    for(int v : g[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
    revTopo.push_back(u);
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> coin[i];
    }

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].push_back(v);
    }

    memset(vis, false, sizeof(vis));;
    for(int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            cnt = 0;
            tarjan(i);
        }
    }

    new_graph();
    memset(vis, false, sizeof(vis));
    for(int i=0; i<scc; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    reverse(revTopo.begin(), revTopo.end());

    for(int i=0; i<scc; i++)
    {
        dp[i] = tot_coins[i];
    }

    ll ret = 0;
    for(int u : revTopo)
    {
        for(int v : g[u])
        {
            dp[v] = max(dp[v], dp[u] + tot_coins[v]);
            ret = max(ret, dp[v]);
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
