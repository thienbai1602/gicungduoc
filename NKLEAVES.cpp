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
const int mxK = 11;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int N, K, w[mxN];
ll dp[mxN][mxK], pref[mxN], com[mxN];

ll query(int a, int b)
{
    return com[b] - com[a - 1] - (ll)a * (pref[b] - pref[a - 1]);
}

void Dp(int x, int l, int r, int nl, int nr)
{
    if (l > r) return;
    int m = (l + r) >> 1, bestID = -1;
    for(int k=nl; k<=min(nr, m); k++)
    {
        ll val = query(k, m);
        if (dp[m][x] > val + dp[k - 1][x - 1])
        {
            dp[m][x] = val + dp[k - 1][x - 1];
            bestID = k;
        }
    }

    if (bestID != -1)
    {
        Dp(x, l, m - 1, nl, bestID);
        Dp(x, m + 1, r, bestID, nr);
    }
}

void solve()
{
    cin >> N >> K;
    for(int i=1; i<=N; i++)
    {
        cin >> w[i];
    }

    set0(pref), set0(com);
    for(ll i=1; i<=N; i++)
    {
        pref[i] = pref[i - 1] + w[i];
        com[i] = com[i - 1] + w[i] * i;
    }

    for(int i=0; i<=N; i++)
    {
        for(int j=0; j<=K; j++)
        {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    for(int k=1; k<=K; k++)
    {
        Dp(k, k, N, k, N);
    }
    cout << dp[N][K];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
