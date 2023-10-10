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
const ll MOD = 1e9 + 7;
const int mxN = 35066;
const int mxK = 66;

int n, K, L = 1, R = 0, cnt = 0;
int a[mxN], occ[mxN], dp[mxN][mxK];

void add(int id)
{
    if (occ[a[id]]++ == 0) ++cnt;
}

void del(int id)
{
    if (--occ[a[id]] == 0) --cnt;
}

void cost(int l, int r)
{
    while(l < L) add(--L);
    while(l > L) del(L++);
    while(r < R) del(R--);
    while(r > R) add(++R);
}

void Dp(int x, int l, int r, int nl, int nr)
{
    if (l > r) return;
    int bestID = -1, m = (l + r) >> 1;
    for(int k=nl; k<=min(nr, m); k++)
    {
        cost(k, m);
        if (dp[m][x] < cnt + dp[k - 1][x - 1])
        {
            dp[m][x] = cnt + dp[k - 1][x - 1];
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
    cin >> n >> K;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    set0(occ), set0(dp);
    for(int k=1; k<=K; k++)
    {
        Dp(k, 1, n, 1, n);
    }
    cout << dp[n][K];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
