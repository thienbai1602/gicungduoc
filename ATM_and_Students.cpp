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
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 2e5 + 66;

ll s;
int tc, n;
vector<ll> a, pref, seg;

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = pref[l];
        return;
    }

    int m = (l + r) >> 1;
    build(id << 1, l, m);
    build((id << 1) | 1, m + 1, r);
    seg[id] = min(seg[id << 1], seg[(id << 1) | 1]);
}

void upd(int id, int l, int r, int k)
{
    if (l > k || k > r) return;
    if (l == r && r == k)
    {
        seg[id] = inf;
        return;
    }

    int m = (l + r) >> 1;
    upd(id << 1, l, m, k);
    upd((id << 1) | 1, m + 1, r, k);
    seg[id] = min(seg[id << 1], seg[(id << 1) | 1]);
}

int lower_bound_s(int id, int l, int r, int k)
{
    if (k > r || (l == r && s < -seg[id]))
    {
        return -1;
    }

    if (l == r || s >= -seg[id])
    {
        return r;
    }

    int m = (l + r) >> 1;
    // s < -seg[id] => s < -seg[id << 1] || s < -seg[(id << 1) | 1]
    if (m < k)
    {
        return lower_bound_s((id << 1) | 1, m + 1, r, k);
    }

    if (s < -seg[id << 1])
    {
        return lower_bound_s(id << 1, l, m, k);
    }

    int ans = lower_bound_s((id << 1) | 1, m + 1, r, k);
    return (ans == -1 ? m : ans);


}

void solve()
{
    cin >> n >> s;
    a.assign(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    pref.assign(n, 0);
    for(int i=0; i<n; i++)
    {
        pref[i] = a[i] + (i == 0 ? 0 : pref[i - 1]);
    }

    seg.assign(4 * n, 0);
    build(1, 0, n - 1);
    int st = -1, ed = -2;
    for(int i=0; i<n; i++)
    {
        int idx = lower_bound_s(1, 0, n - 1, i);
        if (idx != -1 && idx - i > ed - st)
        {
            st = i + 1, ed = idx + 1;
        }
        s -= a[i];
        upd(1, 0, n - 1, i);
    }

    if (st == -1) cout << -1 << "\n";
     else cout << st << " " << ed << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
