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
const int mxN = 1e6 + 66;

int N, M;
string S, T;

void minimize(int &a, int b)
{
    if (a == -1 || a > b) a = b;
}

void solve()
{
    cin >> S >> T;
    M = sz(S), N = sz(T);
    S = " " + S, T = " " + T;

    vector<vector<int>> nxtPos(M + 1, vector<int>(27));
    for(char c='a'; c<='z'; c++)
    {
        for(int i=M-1; i>=0; i--)
        {
            nxtPos[i][c - 'a'] = (S[i + 1] == c ? i + 1 : nxtPos[i + 1][c - 'a']);
        }
    }

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    dp[0][0] = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if (dp[i][j] == -1) continue;
            minimize(dp[i + 1][j], dp[i][j]);
            int k = nxtPos[dp[i][j]][T[i + 1] - 'a'];
            if (k > 0)
            {
                minimize(dp[i + 1][j + 1], k);
            }
        }
    }

    int ans = 0;
    for(int mx=min(N, M); mx>0; mx--)
    {
        for(int i=mx; i<=N; i++)
        {
            if (dp[i][mx] != -1)
            {
                ans = mx;
            }
        }
        if (ans != 0) break;
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
