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
const int mxN = 1e5 + 66;

ll n, K;

void solve()
{
    cin >> n >> K;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    vector<ll> dp(K + 1, 0);
    dp[0] = 1;
    for(int i=0; i<n; i++)
    {
        for(int j=K; j>=a[i]; j--)
        {
            if (dp[j - a[i]] != 0)
            {
                (dp[j] += dp[j - a[i]]) %= MOD;
            }
        }
    }
    cout << dp[K];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("TRE.inp", "r", stdin);
    freopen("TRE.out", "w", stdout);
    solve();
    return 0;
}
