#include    <bits/stdc++.h>
#define ll unsigned long long
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

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

ll n, k,  w[566];
bool isPrime[566];

void sieve()
{
    memset(isPrime, false, sizeof(isPrime));
    isPrime[0] = isPrime[1] = true;
    for(int i=2; i*i<=500; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i*i; j<=500; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }
}

void build(int N, int t)
{
    for(int i=2; i<=N; i++)
    {
        if (!isPrime[i])
        {
            int tp = N, ct = 0;
            while(tp > 0)
            {
                ct += t * (tp /= i);
            }
            w[i] += ct;
        }
    }
}

void solve(ll n, ll k)
{
    set0(w);
    build(n, 1), build(k, -1), build(n - k, -1);
    ll ans = 1;
    for(int i=2; i<=n; i++)
    {
        if (!isPrime[i])
        {
            ans *= (ll)(w[i] + 1);
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    sieve();
    while(cin >> n >> k) solve(n, k);
    return 0;
}
