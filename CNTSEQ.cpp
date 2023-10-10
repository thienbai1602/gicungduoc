#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

ll N;

ll pw(ll a, ll b)
{
    ll ret = 1;
    while(b)
    {
        if (b & 1) ret = ((ret % MOD) * (a % MOD)) % MOD;
        a = ((a % MOD) * (a % MOD)) % MOD;
        b >>= 1;
    }
    return ret;
}

void solve()
{
    cin >> N;
    cout << pw(3, N - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CNTSEQ.INP", "r", stdin);
    freopen("CNTSEQ.OUT", "w", stdout);
    solve();
    return 0;
}
