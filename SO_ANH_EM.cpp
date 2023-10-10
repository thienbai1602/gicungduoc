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
const int mxN = 1e6 + 66;

bool isPrime[1500];
ll L, R, dp[19][170][1500];

void sieve()
{
    memset(isPrime, false, sizeof(isPrime));
    isPrime[0] = isPrime[1] = true;
    for(int i=2; i*i<=(int)1500; i++)
    {
        if (!isPrime[i])
        {
            for(int j=i*i; j<=(int)1500; j+=i)
            {
                isPrime[j] = true;
            }
        }
    }
}

ll recur(vector<int> &num, int N, int S, int sq, bool tight)
{
    if (N == 0)
    {
        return (!isPrime[S] && !isPrime[sq]);
    }

    if (dp[N][S][sq] != -1 && !tight) return dp[N][S][sq];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        ans += recur(num, N - 1, S + digit, sq + digit * digit, tight && (digit == limit));
    }
    if (!tight) dp[N][S][sq] = ans;
    return ans;
}

ll sol(ll X)
{
    vector<int> num;
    while(X > 0)
    {
        num.pb(X % 10);
        X /= 10;
    }
    reverse(all(num));
    return recur(num, sz(num), 0, 0, 1);
}

void solve()
{
    cin >> L >> R;
    memset(dp, -1, sizeof(dp));
    cout << sol(R) - sol(L - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("ANHEM.inp", "r", stdin);
    freopen("ANHEM.out", "w", stdout);
    sieve(); solve();
    return 0;
}
