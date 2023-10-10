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
const int mxN = 1e6 + 66;

int tc, N, cnt[mxN], isPrime[mxN];

void sieve()
{
    for(int i=2; i<=(int)1e6; i++)
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

void solve()
{
    cin >> N;
    int mx = 0;
    for(int i=0; i<N; i++)
    {
        int x;
        cin >> x;
        x = abs(x);
        mx = max(mx, x);

        while(x > 1)
        {
            int p = isPrime[x];
            while(x % p == 0)
            {
                x /= p;
            }
            cnt[p]++;
        }
    }

    int ans = 0;
    for(int i=1; i<=mx; i++)
    {
        ans = max(ans, cnt[i]);
        cnt[i] = 0;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif //SKY
    cin >> tc; sieve();
    while(tc--) solve();
    return 0;
}
