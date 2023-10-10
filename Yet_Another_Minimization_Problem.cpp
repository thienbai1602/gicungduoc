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
const int mxN = 1e5 + 66;

int n, K, L = 1, R = 0;
ll dp[mxN][26], a[mxN], occ[mxN], cnt = 0;

ll ck(ll X)
{
    return (X - 1) * X / 2;
}

void add(int id)
{
    ll pref = occ[a[id]];
    ll suf = ++occ[a[id]];
    cnt += ck(suf) - ck(pref);
}

void del(int id)
{
    ll pref = occ[a[id]];
    ll suf = --occ[a[id]];
    cnt += ck(suf) - ck(pref);
}

void C(int l, int r)
{
    while(L > l) add(--L);
    while(L < l) del(L++);
    while(R > r) del(R--);
    while(R < r) add(++R);
}

void compute(int g, int l, int r, int optl, int optr)
{
    if (l > r) return;
    int m = (l + r) >> 1, bestID = -1;
    dp[m][g] = INF;
    for(int k=optl; k<=min(m, optr); k++)
    {
        C(k, m);
        if (dp[m][g] > dp[k - 1][g - 1] + cnt)
        {
            dp[m][g] = dp[k - 1][g - 1] + cnt;
            bestID = k;
        }
    }
    if (bestID == -1) return;
    compute(g, l, m - 1, optl, bestID);
    compute(g, m + 1, r, bestID, optr);
}

void solve()
{
    cin >> n >> K;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    for(int i=1; i<=n; i++)
    {
        C(1, i);
        dp[i][1] = cnt;
    }

    for(int k=2; k<=K; k++)
    {
        compute(k, k, n, 1, n);
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

