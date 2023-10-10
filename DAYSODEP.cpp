#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 5e5 + 55;

int n;
ll a[mxN];
int fen[mxN];
vector<ll> p;
vector<bool> isPrime(1e6 + 55, false);

void sieve()
{
    isPrime[0] = isPrime[1] = true;
    for(int i=2; i*i<=1000000; i++)
    {
        if (isPrime[i] == false)
        {
            for(int j=i*i; j<=1000000; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }

    for(int i=2; i<=1000000; i++)
    {
        if (!isPrime[i]) p.push_back(i);
    }
}

ll pw(ll a, ll b, ll MOD)
{
    ll ret = 1;
    while(b)
    {
        if (b & 1) ret = (ret * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return ret;
}

bool check_composite(ll n, ll a, ll d, ll s)
{
    ll x = pw(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for(int r=0; r<s; r++)
    {
        x = (x % n * x % n) % n;
        if (x == n - 1) return false;
    }
    return true;
}

bool miller_rabin(ll n)
{
    if (n <= 4) return (n == 2 || n == 3);
    ll s = 0, d = n - 1;
    while((d & 1) == 0)
    {
        d >>= 1;
        ++s;
    }

    vector<int> prime = {2, 6, 71};
    for(int a : prime)
    {
        if (n == a) return true;
        if (check_composite(n, a, d, s)) return false;
    }
    return true;
}

int count_of_div(ll X)
{
    ll ans = 1;
    for(int i=0; i<sz(p); i++)
    {
        if (p[i] * p[i] * p[i] > X) break;
        int cnt = 1;
        while(X % p[i] == 0)
        {
            X /= p[i];
            ++cnt;
        }
        ans *= cnt;
    }

    ll tp = (ll)sqrt(X);
    if (miller_rabin(X)) ans *= 2;
     else if (tp * tp == X && miller_rabin(tp)) ans *= 3;
      else if (X != 1) ans *= 4;
    return ans;
}

void update(int id, int mx)
{
    for(; id<=mxN; id+=(id & -id))
    {
        fen[id] = max(fen[id], mx);
    }
}

int get(int id)
{
    int ret = 0;
    for(; id>0; id-=(id & -id))
    {
        ret = max(ret, fen[id]);
    }
    return ret;
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    sieve();
    for(int i=0; i<n; i++)
    {
        a[i] = count_of_div(a[i]);
    }

    int ret = 0;
    for(int i=0; i<n; i++)
    {
        int mx = get(a[i] - 1);
        ret = max(mx + 1, ret);
        update(a[i], mx + 1);
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
