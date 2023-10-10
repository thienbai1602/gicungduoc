#include    <bits/stdc++.h>
#define ll long long
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
const ll mxA = 1e12 + 66;

int tc;
vector<ll> num, p;
bool isPrime[mxN];

void sieve()
{
    memset(isPrime, false, sizeof(isPrime));
    isPrime[0] = isPrime[1] = true;
    for(int i=2; i*i<=(ll)1e6; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i*i; j<=(ll)1e6; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }

    for(int i=2; i<=(ll)1e6; i++)
    {
        if (!isPrime[i])
        {
            p.pb(i);
        }
    }
}

void init()
{
    for(int i=0; i<sz(p); i++)
    {
        ll X = p[i] * p[i];
        for(int j=i+1; j<sz(p); j++)
        {
            if (X * p[j] > mxA / p[j]) break;
            if (X * p[j] * p[j] <= mxA && X * p[j] * p[j] % 3 == 0)
            {
                num.pb(X * p[j] * p[j]);
            }
        }
    }

    for(int i=0; i<sz(p); i++)
    {
        ll X = 1;
        for(int j=0; j<8; j++)
        {
            X *= p[i];
            if (X > mxA) break;
            if (j == 7 && X % 3 == 0) num.pb(X);
        }
    }

    sort(all(num));
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    cout << (upper_bound(all(num), b) - num.begin()) - (lower_bound(all(num), a) - num.begin()) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    sieve(); init();
    cin >> tc;
    while(tc--) solve();
    return 0;
}
