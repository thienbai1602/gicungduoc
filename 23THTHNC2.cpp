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
const int mxN = 20;

int tc;
ll K, dp[mxN][170];
bool isPrime[170];

void sieve()
{
    memset(isPrime, false, sizeof(isPrime));
    isPrime[0] = isPrime[1] = true;
    for(int i=2; i*i<=169; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i*i; j<=169; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }
    memset(dp, -1, sizeof(dp));
}

ll recur(vector<int> &num, int N, int S, bool tight)
{
    if (N == 0)
    {
        return !isPrime[S];
    }

    if (dp[N][S] != -1 && !tight) return dp[N][S];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        ans += recur(num, N - 1, S + digit, tight && (digit == limit));
    }
    if (!tight) dp[N][S] = ans;
    return ans;
}

ll Cnt(ll X)
{
    vector<int> num;
    while(X > 0)
    {
        num.pb(X % 10);
        X /= 10;
    }
    reverse(all(num));
    return recur(num, sz(num), 0, 1);

}

ll bs(ll l, ll r)
{
    ll ans = 0;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (Cnt(m) >= K)
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> K;
    cout << bs(1, 2e18) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    sieve();
    cin >> tc;
    while(tc--) solve();
    return 0;
}
