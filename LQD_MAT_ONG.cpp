#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e6 + 66;

int n;
vector<ll> p;
int isPrime[mxN];
vector<ll> v = {2, 3, 5, 7, 11};

void sieve()
{
    for(int i=1; i<=1000000; i++)
    {
        isPrime[i] = i;
    }

    for(int i=2; i*i<=1000000; i++)
    {
        if (isPrime[i] == i)
        {
            for(int j=i*i; j<=1000000; j+=i)
            {
                isPrime[j] = i;
            }
        }
    }

    for(int i=2; i<=1000000; i++)
    {
        if (isPrime[i] == i)
        {
            p.push_back(i);
        }
    }
}

ll pw(ll a, ll b, ll MOD)
{
    ll res = 1;
    while(b)
    {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

bool check_composite(ll N, ll a, ll d, ll s)
{
    ll x = pw(a, d, N);
    if (x == 1 || x == N - 1) return false;

    for(int r=0; r<s; r++)
    {
        x = (x * x) % N;
        if (x == N - 1) return false;
    }
    return true;
}

bool miller_rabin(ll N)
{
    if (N <= 4)
    {
        return (N == 2 || N == 3);
    }

    ll d = N - 1, s = 0;
    while(d & 1 == 0)
    {
        d >>= 1;
        ++s;
    }

    for(int i=0; i<sz(v); i++)
    {
        ll a = v[i];
        if (N == a) return true;
        if (check_composite(N, a, d, s)) return false;
    }
    return true;
}

ll divisor(ll X)
{
    ll ans = 1;
    for(int i=0; i<sz(p); i++)
    {
        ll tp = p[i], ct = 1;
        if (tp * tp * tp > X) break;
        while(X % tp == 0)
        {
            X /= tp;
            ct++;
        }
        ans *= ct;
    }

    ll sq = (ll)sqrt(X);
    if (miller_rabin(X)) ans *= 2;
     else if (sq * sq == X && miller_rabin(sq)) ans *= 3;
      else if (X != 1) ans *= 4;
    return ans;
}

ll eratosthenes(ll X)
{
    ll ans = 1;
    while(X > 1)
    {
        int p = isPrime[X], ct = 1;
        while(X % p == 0)
        {
            X /= p;
            ++ct;
        }
        ans *= ct;
    }
    return ans;
}

void solve()
{
    cin >> n;
    ll ret = 0;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        ret += x * (x <= 1000000 ? eratosthenes(x) : divisor(x));
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    sieve(); solve();
    return 0;
}
