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
const int mxN = 1e3 + 566;

int N, M, tc;
ll a[mxN], b[mxN], dp[mxN];

void solve()
{
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<M; i++)
    {
        cin >> b[i];
    }

    set0(dp);
    for(int i=0; i<N; i++)
    {
        ll prev, cur = 0;
        for(int j=0; j<M; j++)
        {
            prev = cur;
            if (a[i] >= 2 * b[j]) cur = max(cur, dp[j]);
            if (a[i] == b[j]) dp[j] = max(dp[j], prev + 1);
        }
    }

    ll ans = 0;
    for(int i=0; i<M; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
