#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 998244353;

ll N;

ll sq(ll x)
{
    return (ll)x * x;
}

bool check(ll m, ll X)
{
    return 2 * m * X - X * X <= N;
}

ll bs(ll l, ll r, ll X)
{

    ll ans = 0;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (check(m, X))
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
    cin >> N;
    ll M = (ll)sqrt(N);
    ll ans = (M * (M + 1) / 2) % MOD;

    for(ll x=max(M - 1, 1LL), cur=M; x>=1; x--)
    {
        ll y = bs(cur, N, x);
        //cout << y << " " << x << " " << y - cur << "\n";
        ans = (ans + (y - cur) * x) % MOD;
        cur = y;
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
