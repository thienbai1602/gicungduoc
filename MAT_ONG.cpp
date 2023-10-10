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
const int mxN = 1e5 + 66;

int N, isPrime[mxN * 10];

void sieve()
{
    for(int i=1; i<=(int)1e6; i++)
    {
        isPrime[i] = i;
    }

    for(int i=2; i*i<=(int)1e6; i++)
    {
        if (isPrime[i] == i)
        {
            for(int j=i*i; j<=(int)1e6; j+=i)
            {
                isPrime[j] = i;
            }
        }
    }
}

ll f(ll M)
{
    ll ct = 1;
    while(M > 1)
    {
        int p = isPrime[M], cnt = 0;
        while(M % p == 0)
        {
            ++cnt;
            M /= p;
        }
        ct *= (cnt + 1);
    }
    return ct;
}

void solve()
{
    cin >> N;
    ll ans = 0;
    for(int i=0; i<N; i++)
    {
        ll X;
        cin >> X;
        ans += X * f(X);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("MATONG.inp", "r", stdin);
    freopen("MATONG.out", "w", stdout);
    sieve(); solve();
    return 0;
}
