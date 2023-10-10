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
const int mxN = 2e7 + 66;

ll n, m;
bool isPrime[mxN];

void sieve()
{
    memset(isPrime, false, sizeof(isPrime));
    isPrime[0] = isPrime[1] = true;
    for(int i=2; i*i<=(ll)2e7; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i*i; j<=(ll)2e7; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    if (n < m) swap(n, m);
    ll ans = 0;
    for(int x=2; x<=n+m; x++)
    {
        if (!isPrime[x])
        {
            int nxt = x - 1;
            if (nxt <= n)
            {
                ans += (nxt <= m ? nxt : m);

            } else
            {
                ans += (m - (x - n) + 1);
            }
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    sieve(); solve();
    return 0;
}
