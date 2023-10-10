#include    <bits/stdc++.h>
//#define SKY
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
const int mxN = 1e6 + 66;

int N, M;
string X, Y;

void maximum(string &a, string b)
{
    if (sz(a) < sz(b)) a = b;
    if (sz(a) > sz(b)) return;
    if (a < b) a = b;
}

string clr(string x)
{
    while(x[0] == '0') x.erase(x.begin());
    return x;
}

void solve()
{
    cin >> X >> Y;
    N = sz(X), M = sz(Y);
    string ans = "";
    vector<vector<string>> dp(N + 1, vector<string>(M + 1, ""));
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            if (X[i - 1] >= '0' && X[i - 1] <= '9' && X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + X[i - 1];
                maximum(ans, dp[i][j]);
            } else
            {
                dp[i][j] = "";
            }
        }
    }
    cout << clr(ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif //SKY
    solve();
    return 0;
}
