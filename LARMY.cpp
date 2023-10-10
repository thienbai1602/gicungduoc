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
const int mxN = 5066;

int N, K;
vector<ll> dp_cur(mxN), dp_before(mxN);
ll H[mxN], cost[mxN][mxN];

ll query(int a, int b)
{
    return cost[b][b] - cost[a - 1][b] - cost[b][a - 1] + cost[a - 1][a - 1];
}

void Dp(int l, int r, int nl, int nr)
{
    if (l > r) return;
    int m = (l + r) >> 1, bestID = -1;
    dp_cur[m] = INF;
    for(int k=nl; k<=min(m, nr); k++)
    {
        ll val = query(k, m);
        if (dp_cur[m] > val + dp_before[k - 1])
        {
            dp_cur[m] = val + dp_before[k - 1];
            bestID = k;
        }
    }
    if (bestID != -1)
    {
        Dp(l, m - 1, nl, bestID);
        Dp(m + 1, r, bestID, nr);
    }
}

void solve()
{
    cin >> N >> K;
    for(int i=1; i<=N; i++)
    {
        cin >> H[i];
    }

    set0(cost);
    for(int i=2; i<=N; i++)
    {
        for(int j=1; j<i; j++)
        {
            cost[i][j] = (H[i] < H[j]);
        }
    }

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cost[i][j] += cost[i - 1][j] + cost[i][j - 1] - cost[i - 1][j - 1];
        }
    }

    for(int i=1; i<=N; i++)
    {
        dp_before[i] = query(1, i);
    }

    for(int k=2; k<=K; k++)
    {
        Dp(k, N, k, N);
        dp_before = dp_cur;
    }
    cout << dp_before[N];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
