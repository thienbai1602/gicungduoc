#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxA = 1e7 + 6;
const ll MOD = 1e9 + 7;

int n, s, tp;
ll cnt[mxA], isPrime[mxA];

void sieve()
{
    for(int i=2; i<=10000000; i++)
    {
        isPrime[i] = i;
    }

    for(int i=2; i*i<=1e7; i++)
    {
        if (isPrime[i] != i) continue;
        for(int j=i*i; j<=1e7; j+=i)
        {
            isPrime[j] = i;
        }
    }
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if (b & 1) ans = ((ans % MOD) * (a % MOD)) % MOD;
        a = ((a % MOD) * (a % MOD)) % MOD;
        b >>= 1;
    }
    return ans;
}

void solve()
{
    cin >> n >> s;
    --s;
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; i++)
    {
        ll x;
        if (i == s)
        {
            cin >> tp;
            continue;
        }

        cin >> x;
        while(x > 1)
        {
            ll p = isPrime[x], sz = 0;
            while(x % p == 0)
            {
                ++sz;
                x /= p;
            }
            cnt[p] = max(cnt[p], sz);
        }
    }

    while(tp > 1)
    {
        ll p = isPrime[tp], sz = 0;
        while(tp % p == 0)
        {
            tp /= p;
            ++sz;
        }
        cnt[p] -= sz;
    }

    ll ans = 1;
    for(int i=2; i<=1e7; i++)
    {
        if (cnt[i] > 1)
        {
            ans = (ans * pw(i, cnt[i] / 2 * 2)) % MOD;
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    sieve(); solve();
    return 0;
}
