#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;

const int mxN = 1e5 + 66;

ll K, tree[mxN * 4];
ii points[mxN];
int n;

void reset(int id, int l, int r)
{
    tree[id] = 0;
    if (l == r)
    {
        return;
    }

    int m = (l + r) >> 1;
    reset(id * 2, l, m);
    reset(id * 2 + 1, m + 1, r);
}

void upd(int id, int l, int r, int k, int val)
{
    if (l > k || k > r) return;
    if (l == r && l == k)
    {
        tree[id] += val;
        return;
    }

    int m = (l + r) >> 1;
    upd(id * 2, l, m, k, val);
    upd(id * 2 + 1, m + 1, r, k, val);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

ll get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v)
    {
        return tree[id];
    }

    int m = (l + r) >> 1;
    return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
}

ll Cnt(int X)
{
    ll ret = 0;
    for(int ed=1, st=1; ed<=n; ed++)
    {
        while(points[ed].fi - points[st].fi > X)
        {
            upd(1, 0, 1e5, points[st].se, 1);
            ++st;
        }

        if (points[ed].fi - points[st].fi <= X)
        {
            ret += (ed - st) + get(1, 0, 1e5, max(0LL, points[ed].se - X), min((ll)1e5, points[ed].se + X));
        }
    }
    return ret;
}

int bs(int l, int r)
{
    int ans = -1;
    while(l <= r)
    {
        reset(1, 0, 1e5);
        int m = (l + r) >> 1;
        if (Cnt(m) >= K)
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> K;
    for(int i=1; i<=n; i++)
    {
        cin >> points[i].fi >> points[i].se;
    }

    sort(points + 1, points + 1 + n);
    cout << bs(0, 1e5);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("DIST.INP", "r", stdin);
    freopen("DIST.OUT", "w", stdout);
    solve();
    return 0;
}
