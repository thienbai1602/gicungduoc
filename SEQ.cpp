#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int n, Q;
ll s[mxN], tree[mxN * 4];

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = s[l];
        return;
    }

    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    tree[id] = __gcd(tree[id * 2], tree[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v)
    {
        return tree[id];
    }

    int m = (l + r) >> 1;
    return __gcd(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

void solve()
{
    cin >> n >> Q;
    for(int i=1; i<=n; i++)
    {
        cin >> s[i];
    }

    for(int i=1; i<=n; i++)
    {
        ll x;
        cin >> x;
        s[i] = abs(s[i] - x);
    }

    build(1, 1, n);
    while(Q--)
    {
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, n, l, r) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("SEQ.INP", "r", stdin);
    freopen("SEQ.OUT", "w", stdout);
    solve();
    return 0;
}
