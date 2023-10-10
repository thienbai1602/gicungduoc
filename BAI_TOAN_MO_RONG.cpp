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
const int mxN = 1e3 + 66;

int n, W, dp[mxN][2][2];
ii ps[mxN][2];

bool cmp(ii a, ii b)
{
    ll L = (a.se * b.se) / __gcd(a.se, b.se);
    ll h = L / a.se, k = L / b.se;
    return (h * a.fi < k * b.fi);
}

void solve()
{
    cin >> n >> W;
    for(int i=0; i<n; i++)
    {
        cin >> ps[i][0].fi >> ps[i][0].se;
        ps[i][1] = mp(ps[i][0].se, ps[i][0].fi);
    }

    dp[0][0][0] = dp[0][1][1] = 1;
    for(int i=1; i<n; i++)
    {
        // khong dao so
        int jmax = -1, curW = -1,st = -1;
        for(int w=0; w<=W; w++)
        {
            for(int j=0; j<i; j++)
            {
                if (cmp(ps[j][w], ps[i][0]))
                {
                    // w = 0
                    if (w == 0)
                    {
                        for(int pr=0; pr<=W; pr++)
                        {
                            if (jmax == -1 || dp[j][0][pr] > dp[jmax][curW][st])
                            {
                                jmax = j, curW = w, st = pr;
                            }
                        }
                    } else
                    {
                        if (jmax == -1 || dp[j][1][1] > dp[jmax][curW][st])
                        {
                            jmax = j, curW = 1, st = 1;
                        }
                    }
                }
            }
        }

        if (jmax == -1)
        {
            dp[i][0][0] = 1;
        } else
        {
            dp[i][0][st] = max(dp[i][0][st], dp[jmax][curW][st] + 1);
        }

        if (W > 0)
        {
            int jmax = -1;
            for(int j=0; j<i; j++)
            {
                if (cmp(ps[j][0], ps[i][1]))
                {
                    if (jmax == -1 || dp[j][0][0] > dp[jmax][0][0])
                    {
                        jmax = j;
                    }
                }
            }

            if (jmax == -1) dp[i][1][1] = 1;
             else dp[i][1][1] = max(dp[i][1][1], dp[jmax][0][0] + 1);
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        for(int w=0; w<=W; w++)
        {
            ans = max({ans, dp[i][w][0], dp[i][w][1]});
        }
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
