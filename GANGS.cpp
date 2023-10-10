#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 66;

int n, m, num_component;
int p[mxN], sz[mxN], enemy[mxN];

int findp(int u)
{
    if (u != p[u]) return p[u] = findp(p[u]);
     else return u;
}

void Union(int a, int b)
{
    a = findp(a), b = findp(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
    --num_component;
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        p[i] = i;
        sz[i] = 1;
    }

    num_component = n;
    for(int i=0; i<m; i++)
    {
        char c;
        int u, v;
        cin >> c >> u >> v;
        --u, --v;
        if (c == 'F')
        {
            Union(u, v);
        } else
        {
            if (enemy[u]) Union(v, enemy[u]);
             else enemy[u] = v;
            if (enemy[v]) Union(u, enemy[v]);
             else enemy[v] = u;
        }
    }
    cout << num_component;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
