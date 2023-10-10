#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e5 + 66;

int tc, n, K, R;
ii s[mxN], tree[mxN * 4];
ll pos[mxN], val[mxN];

ii combine(ii a, ii b)
{
    return mp(a.fi + b.fi, a.se + b.se);
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = mp(s[l].fi, 1);
        return;
    }

    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
}

ii get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return mp(0, 0);
    if (u <= l && r <= v)
    {
        return tree[id];
    }

    int m = (l + r) >> 1;
    return combine(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

void upd(int id, int l, int r, int k)
{
    if (l > k || k > r) return;
    if (l == r && r == k)
    {
        tree[id] = mp(0, 0);
        return;
    }

    int m = (l + r) >> 1;
    if (k <= m) upd(id * 2, l, m, k);
     else upd(id * 2 + 1, m + 1, r, k);
    tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
}

bool sf(int ps, ll X)
{
    int id = upper_bound(val + 1, val + 1 + n, X) - val;
    --id;
    ii nxt = get(1, 1, n, 1, id);
    ll S = nxt.fi + (ps - nxt.se) * X;
    return S >= X * K;
}

ll Cnt(int ps, ll l, ll r)
{
    ll ans = 0;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (sf(ps, m))
        {
            ans = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> K >> R;
    for(int i=1; i<=n; i++)
    {
        cin >> s[i].fi;
        s[i].se = i;
    }

    sort(s + 1, s + 1 + n);
    for(int i=1; i<=n; i++)
    {
        val[i] = s[i].fi;
        pos[s[i].se] = i;
    }

    memset(tree, 0, sizeof(tree));
    build(1, 1, n);

    vector<ll> ret;
    for(int i=n; i>R; i--)
    {
        ret.pb(Cnt(i, 0, 1e12));
        upd(1, 1, n, pos[i]);
    }

    for(int i=sz(ret)-1; i>=0; i--)
    {
        cout << ret[i] << (i > 0 ? " " : "\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("GROUP.IN", "r", stdin);
    freopen("GROUP.OUT", "w", stdout);
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
