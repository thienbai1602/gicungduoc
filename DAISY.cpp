#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 266;

int n, m;
int p[mxN], sz[mxN];

int findp(int u)
{
    if (u != p[u]) return p[u] = findp(p[u]);
     else return u;
}

void Union(int a, int b)
{
    a = findp(a), b = findp(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        p[i] = i;
        sz[i] = 1;
    }

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        Union(u, v);
    }

    int ans = 0;
    for(int i=1; i<n; i++)
    {
        if (findp(i) != 0)
        {
            ++ans;
            cout << i + 1 << "\n";
        }
    }

    if (ans == 0) cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
