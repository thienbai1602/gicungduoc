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
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 5e5 + 66;
const int mxM = 1e7 + 66;

int n, m;
ll A[mxM], B[mxM], isPrime[mxM];

void sieve()
{
    for(ll i=2; i<=(ll)1e7+7; i++)
    {
        isPrime[i] = i;
    }

    for(ll i=2; i*i<=(ll)1e7+7; i++)
    {
        if (isPrime[i] == i)
        {
            prime.pb(i);
            for(ll j=i*i; j<=(ll)1e7+7; j+=i)
            {
                isPrime[j] = i;
            }
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
    cin >> n >> m;
    set0(A), set0(B);
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        while(x > 1)
        {
            ll p = isPrime[x], cnt = 0;
            while(x % p == 0)
            {
                x /= p;
                ++cnt;
            }
            A[p] += cnt;
        }
    }

    for(int i=0; i<m; i++)
    {
        ll x;
        cin >> x;
        while(x > 1)
        {
            ll p = isPrime[x], cnt = 0;
            while(x % p == 0)
            {
                x /= p;
                ++cnt;
            }
            B[p] += cnt;
        }
    }

    ll ans = 1;
    for(int i=2; i<=(ll)1e7+7; i++)
    {
        ans = ((ans % MOD) * (pw((ll)i, min(A[i], B[i])) % MOD)) % MOD;
    }
    cout << ans % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    sieve(); solve();
    return 0;
}

