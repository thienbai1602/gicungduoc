#include    <bits/stdc++.h>
//#define SKY
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
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;
const int mxK = 2e3 + 66;

ll N, K, mod;
bool isPrime[mxN];
ll fac[mxN], inv[mxN], dp[mxK][mxK], pr[mxN];

ll pw(ll a, ll b, ll M)
{
    ll ret = 1;
    while(b)
    {
        if (b & 1) ret = (ret * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ret % M;
}

void init()
{
    for(int i=0; i<=(int)2e3; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for(int i=1; i<=(int)2e3; i++)
    {
        for(int j=1; j<=i; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
        }
    }

    memset(isPrime, false, sizeof(isPrime));
    isPrime[0] = isPrime[1] = true;
    for(int i=2; i*i<=(int)1e5; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i*i; j<=(int)1e5; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }

    fac[0] = 1;
    for(ll i=1; i<=(int)1e5; i++)
    {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    for(int i=0; i<=(int)1e5; i++)
    {
        inv[i] = pw(fac[i], MOD - 2, MOD) % MOD;
    }
}

void build(int N, int t)
{
    for(int x=2; x<=N; x++)
    {
        if (!isPrime[x])
        {
            int nxt = N;
            while(nxt > 0)
            {
                pr[x] += t * (nxt /= x);
            }
        }
    }
}

void sub1()
{
    cout << dp[N][K] % mod << "\n";
}

void sub2()
{
    set0(pr);
    build(N, 1); build(K, -1); build(N - K, -1);
    ll ans = 1;
    for(int x=2; x<=N; x++)
    {
        if (!isPrime[x])
        {
            ans = (ans * pw(x, pr[x], mod)) % mod;
        }
    }
    cout << ans;
}

void sub3()
{
    cout << (((fac[N] % MOD) * (inv[K] % MOD)) % MOD * (inv[N - K] % MOD)) % MOD << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif  //SKY
    int sub, tc;
    cin >> sub >> tc >> mod;
    init();
    while(tc--)
    {
        cin >> N >> K;
        if (sub == 1) sub1();
         else if (sub == 2) sub2();
          else sub3();
    }
    return 0;
}
