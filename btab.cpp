#include    <bits/stdc++.h>
//#define SKY
#define ll long long
#define ld long double
#define MASK(x) (1LL << x)
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define pi pair<int, int>
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

void solve()
{
    cin >> N >> M;
    vector<int> a(N, 0);
    for(int i=0; i<N; i++)
    {
        cin >> a[i];
    }

    vector<int> b(M, 0), prefB(M, 0);
    for(int j=0; j<M; j++)
    {
        cin >> b[j];
        prefB[j] = b[j] + (j == 0 ? 0 : prefB[j - 1]);
    }

    vector<pi> seg;
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for(int i=N-1; i>=0; i--)
    {
        for(int j=M-1; j>=0; j--)
        {
            dp[i][j] = (a[i] == b[j] && a[i] != 0 ? dp[i + 1][j + 1] + 1 : 0);
            if (dp[i][j]) seg.pb(mp(j, j + dp[i][j] -1));
        }
    }

    int ans = 0;
    for(auto [L, R] : seg)
    {
        for(int x=L; x<=R; x++)
        {
            ans += (prefB[x] - prefB[L - 1] == 0);
        }
    }
    cout << ans;
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
