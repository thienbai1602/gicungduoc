#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mxN = 5e4 + 66;
const ll INF = 1e18;

int n, Q;
ll a[mxN];
ii tree[mxN * 4];

ii combine(ii x, ii y)
{
    return mp(max(x.fi, y.fi), min(x.se, y.se));
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = mp(a[l], a[l]);
        return;
    }

    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
}

ii get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l || l > r || u > v) return mp(-INF, INF);
    if (u <= l && r <= v)
    {
        return tree[id];
    }

    int m = (l + r) >> 1;
    return combine(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

void solve()
{
    cin >> n >> Q;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);

    while(Q--)
    {
        int l, r;
        cin >> l >> r;
        ii ans = get(1, 1, n, l, r);
        cout << ans.fi - ans.se << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
