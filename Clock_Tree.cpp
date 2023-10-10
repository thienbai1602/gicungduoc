#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int mxN = 2566;

int n;
ll a[mxN], sum0 = 0, sum1 = 0, node0 = 0, node1 = 0;
vector<int> edges[mxN];

void dfs(int u, int col, int p)
{
    if (col == 0)
    {
        sum0 += a[u];
        node0++;
    } else
    {
        sum1 += a[u];
        node1++;
    }

    for(int v : edges[u])
    {
        if (v != p)
        {
            dfs(v, 1 - col, u);
        }
    }
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    dfs(0, 0, n + 1);

    if ((sum0 % 12) == (sum1 % 12))
    {
        cout << n;
    } else
     if ((sum1 + 1) % 12 == sum0 % 12)
     {
         cout << node0;
     } else
      if ((sum0 + 1) % 12 == sum1 % 12)
      {
          cout << node1;
      } else
       cout << 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    solve();
    return 0;
}
