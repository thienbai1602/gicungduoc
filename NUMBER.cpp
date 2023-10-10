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

int n, K, a[mxN];
ll dp[mxN][36];

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    cin >> K;

    if (K == 1)
    {
        ll ans = 0;
        for(int i=1; i<=n; i++)
        {
            ans += !(a[i] & 1);
        }
        cout << ans;
        return;
    }

    // dp[i][k] số cách chọn i đồ vật đầu tiên, kết thúc tại i và lấy k đồ vật có nghĩa
    vector<ll> S(K + 1, 0);
    for(int i=1; i<=n; i++)
    {
        for(int k=min(i, K); k>0; k--)
        {
            if (k == 1)
            {
                if (a[i] == 0) dp[i][k] = 0;
                 else
                 {
                     dp[i][k] = 1;
                     ++S[k];
                 }
            } else
            {
                (dp[i][k] += S[k - 1]) %= MOD;
                (S[k] += dp[i][k]) %= MOD;
            }
        }
    }

    ll ans = 0;
    for(int i=K; i<=n; i++)
    {
        if (a[i] % 2 == 0)
        {
            (ans += dp[i][K]) %= MOD;
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
