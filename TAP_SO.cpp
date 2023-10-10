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
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

ll m;
int n, isPrime[mxN];

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
    cin >> n >> m;
    vector<ll> oc(n + 1);
    for(int x=1; x<=n; x++)
    {
        int nxt = x, cnt = 1;
        while(nxt > 1)
        {
            int p = isPrime[nxt], ct = 0;
            while(nxt % p == 0)
            {
                nxt /= p;
                ++ct;
            }
            if (ct & 1) cnt *= p;
        }
        ++oc[cnt];
    }

    ll ans = 1;
    for(int i=1; i<=n; i++)
    {
        (ans *= (oc[i] + 1)) %= m;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    sieve(); solve();
    return 0;
}
