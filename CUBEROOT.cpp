#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;
const ll MOD = 1e9 + 7;

int tc;
int n, isPrime[mxN];

void sieve()
{
    for(int i=1; i<=100005; i++)
    {
        isPrime[i] = i;
    }

    for(int i=2; i*i<=100005; i++)
    {
        if (isPrime[i] == i)
        {
            for(int j=i*i; j<=100005; j+=i)
            {
                isPrime[j] = i;
            }
        }
    }
}

ll pwr(ll a, ll b)
{
    if (b == 0) return 1;
    if (b == 1) return (a % MOD);
    ll t = pwr(a, b / 2);
    t = ((t % MOD) * (t % MOD)) % MOD;
    return (b % 2 == 0 ? t % MOD : ((t % MOD) * (a % MOD)) % MOD);
}

void solve()
{
    cin >> n;
    vector<int> cnt(mxN - 1, 0);
    for(int i=1; i<=n; i++)
    {
        int X = i;
        while(X > 1)
        {
            int p = isPrime[X];
            int ct = 0;
            while(X % p == 0)
            {
                cnt[p]++;
                ct++;
                X /= p;
            }
        }
    }

    ll ret = 1;
    for(int i=2; i<=n; i++)
    {
        if (cnt[i] > 2)
        {
            int pw = cnt[i] / 3 * 3;
            ret = (ret % MOD * pwr(i, pw) % MOD) % MOD;
        }
    }
    cout << ret << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CUBEROOT.INP", "r", stdin);
    freopen("CUBEROOT.OUT", "w", stdout);
    sieve();
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
