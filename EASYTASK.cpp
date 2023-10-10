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

int n;
ll a[mxN], pref[mxN];
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
}

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    for(int i=1; i<=n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    sieve();

    ll ans = -INF, mi = 0;
    for(int i=2; i<=n; i++)
    {
        if (!isPrime[i])
        {
            mi = (i == 2 ? pref[i - 1] : min(mi, pref[i - 1]));
            ans = max(ans, pref[i] - mi);
        } else continue;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

