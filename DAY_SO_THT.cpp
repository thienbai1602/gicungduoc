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
const ll MODK = MOD * 6;
const int mxN = 1e6 + 66;

ll N;

ll S(ll lim)
{
    ll K = MOD * 6;
    ll ans = ((lim % K) * (lim + 1) % K * (2 * lim + 1) % K) % K;
    return (ans / 6) % MOD;
}

void solve()
{
    cin >> N;
    ll l = 1, r = 1e10, lim = 0;
    while(l <= r)
    {
        ll m = l + (r - l) / 2;
        if (m * (m + 1) / 2 <= N)
        {
            lim = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }

    ll ans = S(lim);
    ll ret = ((lim + 1) % MOD * (N - (lim * (lim + 1) / 2)) % MOD) % MOD;
    ll res = (ans + ret) % MOD;
    cout << (res + MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
