#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int n, Q;
ll a[mxN], tree[mxN * 4], lz[mxN * 4];

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = a[l];
        return;
    }

    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r, u, v);
}

void solve()
{
    cin >> n >> Q;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
