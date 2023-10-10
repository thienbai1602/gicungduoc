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
const ll MOD = 2004010501;
const int mxN = 1e3 + 66;

ll dp[mxN][mxN];
int numRow, numCol, K;
bool matrix[mxN][mxN];

bool sf(int dy, int dx, int edy, int edx)
{
    int x = (edx + dx - 1) % numCol + 1;
    int y = (edy + dy - 1) % numRow + 1;
    return !matrix[y][x];
}

void solve()
{
    cin >> numRow >> numCol >> K;
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            char chr;
            cin >> chr;
            matrix[r][c] = (chr == '#');
        }
    }

    dp[1][1] = 1;
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            if (r == 1 && c == 1) continue;
            if (sf(r - 1, c - 1, r, c))
            {
                if (sf(r - 1, c - 2, r, c)) (dp[r][c] += dp[r][c - 1]) %= MOD;
                if (sf(r - 2, c - 1, r, c)) (dp[r][c] += dp[r - 1][c]) %= MOD;
            }
        }
    }
    cout << dp[numRow][numCol] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
