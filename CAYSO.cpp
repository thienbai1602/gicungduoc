#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 466;

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
        adj[u].pb(i), adj[v].pb(i + m);
    }

    stack<int> st; st.push(0);
    memset(del, 0, sizeof(del));
    while(!st.empty())
    {
        int u = st.top();
        bool flat = false;
        for(int i=0; i<sz(edges[u]); i++)
        {
            int v = edges[u][i], c = adj[u][i];
            if (!del[c])
            {
                del[c] = 1;
                st.push(v);
                flat = true;
                break;
            }
        }

        if (!flat)
        {
            st.pop();
            path.pb(u);
        }
    }

    for(int x : path) cout << x + 1 << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
