#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
const ll modV = MOD * 2;

ll N;

ll total(ll a, ll b)
{
    return ((((a + b) % modV) * ((b - a + 1) % modV) % modV) / 2) % MOD;
}

void solve()
{
    cin >> N;
    ll ans = 0;
    for(ll i=1, j; i<=N; i=j)
    {
        ll q = N / i;
        j = N / q + 1;
        ans = (ans % MOD + (total(i, j - 1) % MOD) * (q % MOD) % MOD) % MOD;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
