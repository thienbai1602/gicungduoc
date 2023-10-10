#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 166;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int tc;
ll N, K, sz, pref[mxN];

ll pw(ll a, ll b)
{
    if (b == 0) return 1;
    if (b == 1) return a % MOD;
    ll t = pw(a, b/2);
    t = ((t % MOD) * (t % MOD)) % MOD;
    return b % 2 == 0 ? t % MOD : ((a % MOD) * (t % MOD));
}

ll sol(ll X)
{
    if (X == 0) return 0;
    int ps = lower_bound(pref, pref + sz + 1, X) - pref;
    return pw(N, ps) + sol(X - pref[ps - 1] - 1);
}

void solve()
{
    cin >> N >> K;
    cout << sol(K) % MOD << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    pref[0] = 1;
    for(sz=1; sz<31; sz++)
    {
        pref[sz] = pref[sz - 1] + (1 << sz);
    }
    while(tc--) solve();
    return 0;
}
