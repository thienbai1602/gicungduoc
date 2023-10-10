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
const int mxN = 1e4 + 66;

int n, K;
ll a[mxN], dp[mxN];

void solve()
{
    cin >> n >> K;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    dp[0] = 1;
    ll ans = 1;
    for(int i=1; i<n; i++)
    {
        int imax = -1;
        for(int j=0; j<i; j++)
        {
            if (a[i] - a[j] >= K)
            {
                if (imax == -1 || dp[imax] < dp[j])
                {
                    imax = j;
                }
            }
        }
        dp[i] = (imax == -1 ? 1 : dp[imax] + 1);
        ans = max(ans, dp[i]);
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
