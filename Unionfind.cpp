#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 2e5 + 66;

int n, Q;
int link[mxN], sz[mxN];

int findp(int u)
{
    if (u != link[u]) return link[u] = findp(link[u]);
     else return u;
}

void Union(int a, int b)
{
    a = findp(a), b = findp(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += b;
    link[b] = a;
}

void solve()
{
    cin >> n >> Q;
    for(int i=0; i<n; i++)
    {
        link[i] = i;
        sz[i] = 1;
    }

    for(int i=0; i<Q; i++)
    {
        int tc, u, v;
        cin >> tc >> u >> v;
        if (tc == 0)
        {
            Union(u, v);
        } else
        {
            cout << (findp(u) == findp(v)) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
