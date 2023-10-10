#include    <bits/stdc++.h>
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 5e5 + 66;

struct query
{
    int id, l, r;
    query(int _id = 0, int _l = 0, int _r = 0)
    {
        id = _id, l = _l , r = _r;
    }

    bool operator < (const query &v)
    {
        return r < v.r;
    }
};

ll seg[mxN * 4];
int n, Q, a[mxN];

void upd(int id, int l, int r, int k, ll x)
{
    if (l > k || k > r) return;
    if (l == r && k == r)
    {
        seg[id] = x;
        return;
    }
    int m = (l + r) >> 1;
    upd(id << 1, l, m, k, x);
    upd((id << 1) | 1, m + 1, r, k, x);
    seg[id] = min(seg[id << 1], seg[(id << 1) | 1]);
}

ll get(int id, int l, int r, int u, int v)
{
    if (l > v || u > r) return INF;
    if (seg[id] >= u) return INF;
    if (l == r) return a[l];
    int m = (l + r) >> 1;
    ll tp = get(id << 1, l, m, u, v);
    return (tp != INF ? tp : get((id << 1) | 1, m + 1, r, u, v));
}

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    vector<int> cnt(mxN, 0), lw(n + 1);
    for(int i=1; i<=n; i++)
    {
        lw[i] = cnt[a[i]];
        cnt[a[i]] = i;
    }

    cin >> Q;
    vector<query> listID;
    for(int i=0; i<Q; i++)
    {
        int L, R;
        cin >> L >> R;
        listID.pb(query(i, L, R));
    }

    sort(all(listID));
    vector<int> ans(Q);
    int r = 0;
    for(auto [id, L, R] : listID)
    {
        while(r < R)
        {
            ++r;
            if (lw[r] != 0) upd(1, 1, n, lw[r], INF);
            upd(1, 1, n, r, lw[r]);
        }
        ll nxt = get(1, 1, n, L, R);
        ans[id] = (nxt != INF ? nxt : 0);
    }

    for(int i=0; i<Q; i++)
    {
        cout << ans[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

