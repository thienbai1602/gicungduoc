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
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e3 + 66;

int numRow, numCol;
ll a[mxN][mxN];

bool ck(int X)
{
    vector<vector<ll>> dp(numRow + 1, vector<ll>(numCol + 1, inf));
    dp[1][1] = (a[1][1] < X);
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            if (r * c == 1) continue;
            if (r > 1) dp[r][c] = min(dp[r][c], dp[r - 1][c] + (a[r][c] < X));
            if (c > 1) dp[r][c] = min(dp[r][c], dp[r][c - 1] + (a[r][c] < X));
        }
    }
    return dp[numRow][numCol] < (numRow + numCol) / 2;
}

void solve()
{
    cin >> numRow >> numCol;
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            cin >> a[r][c];
        }
    }

    int ans = 0, lo = 0, hi = numRow * numCol;
    while(lo <= hi)
    {
        int m = (lo + hi) >> 1;
        if (ck(m))
        {
            ans = m;
            lo = m + 1;
        } else
        {
            hi = m - 1;
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
