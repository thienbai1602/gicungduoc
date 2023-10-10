#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e18;
const int mxN = 5e5 + 55;

int n, Q;
ll a[mxN], seg[mxN * 4];

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = a[l];
        return;
    }

    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v)
{
    if (l > v || u > r)
    {
        return INF;
    }

    if (u <= l && r <= v)
    {
        return seg[id];
    }

    int m = (l + r) >> 1;
    return min(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

void solve()
{
    cin >> n >> Q;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    build(1, 0, n - 1);

    while(Q--)
    {
        int u, v;
        cin >> u >> v;
        cout << get(1, 0, n - 1, u, v - 1) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
