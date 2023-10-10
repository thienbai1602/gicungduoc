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
const int mxN = 1e6 + 66;

int n;
ll it[mxN];

void upd(int id, int x)
{
    for(; id<=n; id+=(id & -id))
    {
        it[id] += x;
    }
}

ll get(int id)
{
    ll ret = 0;
    for(; id>0; id-=(id & -id))
    {
        ret += it[id];
    }
    return ret;
}

void solve()
{
    cin >> n;
    vector<ll> seg, a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        seg.pb(a[i]);
    }

    sort(all(seg));
    seg.erase(unique(all(seg)), seg.end());

    set0(it);
    vector<int> store(n + 1, 0), cnt(n + 1, 0);
    for(int i=n-1; i>=0; i--)
    {
        int idx = upper_bound(all(seg), a[i]) - seg.begin();
        store[i] = ++cnt[idx];
        upd(cnt[idx], 1);
    }

    ll ans = 0;
    vector<int> ct(n + 1, 0);
    for(int i=0; i<n; i++)
    {
        int idx = upper_bound(all(seg), a[i]) - seg.begin();
        upd(cnt[idx]--, -1);
        ans += get(ct[idx]++);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
