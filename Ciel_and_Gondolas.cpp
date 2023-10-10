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
const int mxK = 866;
const ll MOD = 1e9 + 7;
const int mxN = 4e3 + 66;

int N, K;
ll dp[mxN][mxK], u[mxN][mxN], pref[mxN][mxN];

void compute(int g, int l, int r, int optl, int optr)
{
    if (l > r) return;
    int bestID = -1, m = (l + r) >> 1;
    for(int k=optl; k<=min(optr, m); k++)
    {
        ll nxt = dp[k - 1][g - 1] + (pref[m][m] - pref[m][k - 1] - pref[k - 1][m] + pref[k - 1][k - 1]);
        if (nxt < dp[m][g])
        {
            dp[m][g] = nxt;
            bestID = k;
        }
    }
    if (bestID == -1) return;
    compute(g, l, m - 1, optl, bestID);
    compute(g, m + 1, r, bestID, optr);
}

void solve()
{
    cin >> N >> K;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            char c;
            cin >> c;
            u[i][j] = (int)(c - '0');
        }
    }

    set0(pref);
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] + u[i][j] - pref[i - 1][j - 1];
        }
    }

    for(int row=0; row<=N; row++)
    {
        fill(dp[row], dp[row] + K + 1, INF);
    }

    dp[0][0] = 0;
    for(int gr=1; gr<=K; gr++)
    {
        compute(gr, gr, N, 1, N);
    }
    cout << dp[N][K] / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
