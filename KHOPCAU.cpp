#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e5 + 55;

int n, m, cnt = 0;
bool vis[mxN];
stack<int> st;
int low[mxN], num[mxN], p[mxN], child[mxN], khop[mxN];
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
                child[u]++;
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
        edges[v].push_back(u);
    }

    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            p[i] = -1;
            cnt = 0;
            tarjan(i);
        }
    }

    int ct_khop = 0;
    memset(khop, 0, sizeof(khop));
    for(int v=0; v<n; v++)
    {
        if (p[v] == -1) continue;
        if (num[v] > 1)
        {
            int u = p[v];
            if (low[v] >= num[u])
            {
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

    vector<int> ans_khop;
    for(int i=0; i<n; i++)
    {
        if (khop[i]) ans_khop.push_back(i);
    }

    vector<int> ans_cau;
    for(int v=0; v<n; v++)
    {
        if (p[v] == -1) continue;
        if (num[v] > 1 && low[v] >= num[v])
        {
            ans_cau.push_back(v);
        }
    }

    cout << sz(ans_khop) << " " << sz(ans_cau) << "\n";
    for(int v : ans_khop)
    {
        cout << v + 1 << "\n";
    }

    for(int v : ans_cau)
    {
        cout << v + 1 << " " << p[v] + 1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
