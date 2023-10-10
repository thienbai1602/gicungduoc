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
const int mxN = 2e6 + 66;

int n;
vector<ll> a;
bool isPrime[mxN];

bool diff(ll X)
{
    int odd = 0, sz = 0;
    while(X > 0)
    {
        odd += ((X % 10) & 1);
        X /= 10;
        ++sz;
    }
    return (odd * 2 != sz);
}

bool prime(ll X)
{
    if (X <= 4) return (X == 2 || X == 3);
    for(ll i=2; i*i<=X; i++)
    {
        if (X % i == 0) return false;
    }
    return true;
}

void sub1()
{
    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        if (diff(a[i]) && prime(a[i]))
        {
            ++ans;
        }
    }
    cout << ans;
}

void sieve()
{
    memset(isPrime, false, sizeof(isPrime));
    isPrime[0] = isPrime[1] = true;
    for(int i=2; i*i<=(int)2e6; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i*i; j<=(int)2e6; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }
}

void sub2()
{
    sieve();
    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        if (diff(a[i]) && !isPrime[a[i]])
        {
            ++ans;
        }
    }
    cout << ans;
}

void solve()
{
    cin >> n;
    a.resize(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    if (n <= 300) sub1();
     else sub2();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
