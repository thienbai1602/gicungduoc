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

int n, m;
vector<ll> a;
multiset<ll> low, up;

void ins(ll x, int K)
{
    ll val = *low.rbegin();
    if (x > val)
    {
        up.insert(x);
        if (sz(up) > K / 2)
        {
            low.insert(*up.begin());
            up.erase(up.find(*up.begin()));
        }
    } else
    {
        low.insert(x);
        if (sz(low) > (K + 1) / 2)
        {
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

int Cnt(ll X)
{
    low.clear(), up.clear();
    int ans = 1;
    int l = 0, r = 0;
    low.insert(a[0]);
    while(r < n - 1)
    {
        ++r;
        ins(a[r], r - l + 1);
        ll median = *low.rbegin();
        ll nxt = 0;
        for(int x=l; x<=r; x++)
        {
            nxt += abs(median - a[x]);
        }

        if (nxt > X)
        {
            ++ans;
            low.clear(), up.clear();
            low.insert(a[r]);
            l = r;
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> m;
    a.assign(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll l = 0, r = inf, ans = 0;
    while(l <= r)
    {
        ll mid = (l + r) >> 1;
        if (Cnt(mid) <= m)
        {
            r = mid - 1;
            ans = mid;
        } else
        {
            l = mid + 1;
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
