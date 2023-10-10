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

const int LOG = 18;
const ll INF = (ll)1e18;
const int mxM = 266;
const ll MOD = 1e9 + 7;
const int mxN = 5e3 + 66;

int N, M, lg[mxN];
ll a[mxN], B[mxM][mxN][LOG], dp[mxN];

ll query(int l, int r)
{
    ll ans = 0;
    int k = lg[r - l + 1];
    for(int j=1; j<=M; j++)
    {
        ans += max(B[j][l][k], B[j][r - (1 << k) + 1][k]);
    }
    return ans - (a[r] - a[l]);
}

void Dp(int l, int r, int nl, int nr)
{
    if (l > r) return;
    int m = (l + r) >> 1, bestID = -1;
    for(int k=nl; k<=min(nr, m); k++)
    {
        ll val = query(k, m);
        if (dp[m] < val)
        {
            dp[m] = val;
            bestID = k;
        }
    }
    if (bestID != -1)
    {
        Dp(l, m - 1, nl, bestID);
        Dp(m + 1, r, bestID, nr);
    }
}

void solve()
{
    cin >> N >> M;
    for(int i=2; i<=N; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            cin >> B[j][i][0];
        }
    }

    fill(dp, dp + N + 1, -INF);

    lg[1] = 0;
    for(int i=2; i<=N; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    for(int j=1; j<=M; j++)
    {
        for(int k=1; (1<<k)<=N; k++)
        {
            for(int i=1; i+(1 << k)-1<=N; i++)
            {
                B[j][i][k] = max(B[j][i][k - 1], B[j][i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    Dp(1, N, 1, N);

    ll ans = -INF;
    for(int i=1; i<=N; i++)
    {
        ans = max(ans, dp[i]);
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
