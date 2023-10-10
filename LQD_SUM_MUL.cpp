#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 5e5 + 66;

int n;
ll p, a[mxN];
map<ll, ll> ma;

ll euler(ll X)
{
    ll ans = X, pr = 2;
    while(pr * pr <= X)
    {
        if (X % pr == 0)
        {
            ans -= ans / pr;
            while(X % pr == 0)
            {
                X /= pr;
            }
        }
        ++pr;
    }
    return (X > 1 ? ans - ans / X : ans);
}

ll inv(ll a, ll b, ll mod)
{
    ll ret = 1;
    while(b)
    {
        if (b & 1) ret = ((ret % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        b >>= 1;
    }
    return ret;
}

void solve()
{
    cin >> n >> p;
    ll MOD = euler(p);
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        a[i] = (x - 1 + p) % p;
    }

    ll ret = 0;
    for(int i=0; i<n; i++)
    {
        if (__gcd(a[i], p) == 1)
        {
            ll nxt = inv(a[i], MOD - 1, p);
            if (ma[nxt]) ret += ma[nxt];
            //cout << nxt << " " << ret << "\n";
            ++ma[a[i]];
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
