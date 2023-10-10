#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;

int n;
ll a, b;

ll pw(ll a, ll b)
{
    ll ret = 1;
    while(b)
    {
        if (b & 1) ret = (ret % MOD * a % MOD) % MOD;
        a = (a % MOD * a % MOD) % MOD;
        b >>= 1;
    }
    return ret;
}

void solve()
{
    cin >> n;
    ll div_cnt2 = 1, div_sum = 1, div_prod = 1, div_cnt = 1;;
    for(int i=0; i<n; i++)
    {
        cin >> a >> b;
        div_cnt = (div_cnt % MOD * (b + 1) % MOD) % MOD;
        div_sum = (div_sum % MOD * (pw(a, b + 1) - 1 + MOD) % MOD * pw(a - 1, MOD - 2) % MOD) % MOD;
        div_prod = (pw(div_prod, b + 1) % MOD * pw(pw(a, b * (b + 1) / 2), div_cnt2) % MOD) % MOD;
        div_cnt2 = (div_cnt2 % (MOD - 1) * (b + 1) % (MOD - 1)) % (MOD - 1);
    }
    cout << div_cnt << " " << div_sum << " " <<  div_prod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
