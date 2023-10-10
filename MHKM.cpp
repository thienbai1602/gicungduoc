#include    <bits/stdc++.h>
#define SKY
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
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 5e2 + 66;
const int mxM = 5e4 + 66;

int N, M;
int x[mxN], y[mxN], z[mxN], dp[mxN][mxM], val[mxN][mxM];

void solve()
{
    cin >> N >> M;
    for(int i=1; i<=N; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
    }

    set0(dp);
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<=M; j++)
        {
            for(int u=0; u<=min(z[i], j / x[i]); u++)
            {
                if (dp[i - 1][j - (u * x[i])] + y[i] * u > dp[i][j])
                {
                    dp[i][j] = dp[i - 1][j - (u * x[i])] + u * y[i];
                    val[i][j] = u;
                }
            }
        }
    }

    int ans = -1, w = -1;
    for(int j=0; j<=M; j++)
    {
        if (ans <= dp[N][j])
        {
            ans = dp[N][j];
            w = j;
        }
    }

    vector<int> ret(N, 0);
    for(int i=N; i>0; i--)
    {
        ret[i - 1] = val[i][w];
        w -= val[i][w] * x[i];
    }

    cout << ans << "\n";
    for(int &x : ret) cout << x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif //SKY
    solve();
    return 0;
}
