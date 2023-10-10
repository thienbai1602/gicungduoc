#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int mxN = 2e5 + 66;

int n;
ll firstMax[mxN], secondMax[mxN], c[mxN];
vector<int> edges[mxN];

void dfs1(int u, int p)
{
    firstMax[u] = secondMax[u] = 0;
    for(int v : edges[u])
    {
        if (v != p)
        {
            dfs1(v, u);
            if (firstMax[u] < firstMax[v] + 1)
            {
                secondMax[u] = firstMax[u];
                firstMax[u] = firstMax[v] + 1;
                c[u] = v;
            } else
            {
                secondMax[u] = max(secondMax[u], firstMax[v] + 1);
            }
        }
    }
}

void dfs2(int u, int p)
{
    for(int v : edges[u])
    {
        if (v != p)
        {
            if (c[u] == v)
            {
                if (secondMax[u] + 1 > firstMax[v])
                {
                    secondMax[v] = firstMax[v];
                    firstMax[v] = secondMax[u] + 1;
                    c[v] = u;
                } else
                {
                    secondMax[v] = max(secondMax[v], secondMax[u] + 1);
                }
            } else
            {
                if (firstMax[u] + 1 > firstMax[v])
                {
                    secondMax[v] = firstMax[v];
                    firstMax[v] = firstMax[u] + 1;
                    c[v] = u;
                }
            }
            dfs2(v, u);
        }
    }
}

void solve()
{
    cin >> n;
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    dfs1(0, n + 1);
    dfs2(0, n + 1);

    for(int i=0; i<n; i++)
    {
        cout << firstMax[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
