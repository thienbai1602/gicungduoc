#include    <bits/stdc++.h>
//#define SKY
#define ll long long
#define ld long double
#define MASK(x) (1LL << x)
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
const int mxN = 101;
const int max5 = 2501;

int n, K, dp[mxN][mxN][max5 + 1];

int fac(ll x, ll p)
{
    int ans = 0;
    while(x % p == 0)
    {
        ++ans;
        x /= p;
    }
    return ans;
}

void solve()
{
    cin >> n >> K;
    fill(&dp[0][0][0], &dp[100][100][2501], -1);
    for(int i=0; i<=n; i++)
    {
        dp[i][0][0] = 0;
    }

    for(int i=1; i<=n; i++)
    {
        ll x;
        cin >> x;
        int cnt2 = fac(x, 2), cnt5 = fac(x, 5);
        for(int j=1; j<=K; j++)
        {
            for(int m=0; m<=max5; m++)
            {
                dp[i][j][m] = dp[i - 1][j][m];
                if (m >= cnt5 && dp[i - 1][j - 1][m - cnt5] != -1)
                {
                    dp[i][j][m] = max(dp[i][j][m], dp[i - 1][j - 1][m - cnt5] + cnt2);
                }
            }
        }
    }

    int ans = 0;
    for(int m=0; m<=max5; m++)
    {
        ans = max(ans, min(m, dp[n][K][m]));
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif //SKY
    solve();
    return 0;
}
