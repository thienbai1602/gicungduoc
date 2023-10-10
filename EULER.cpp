#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 4e5 + 66;

int n, m, del[mxN];
vector<int> path, edges[mxN], adj[mxN];

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
        adj[u].pb(i), adj[v].pb(i);
    }

    stack<int> st; st.push(0);
    memset(del, 0, sizeof(del));
    while(!st.empty())
    {
        bool flat = false;
        int u = st.top();
        for(int i=0; i<sz(edges[u]); i++)
        {
            int v = edges[u][i], c = adj[u][i];
            if (!del[c])
            {
                st.push(v);
                del[c] = 1;
                flat = true;
                break;
            }
        }

        if (!flat)
        {
            st.pop();
            path.pb(u + 1);
        }
    }

    for(int x : path)
    {
        cout << x << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
