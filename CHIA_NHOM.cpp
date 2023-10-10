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

int N, G, L = 1, R = 0, cnt = 0;
ll c[mxN], dp[mxN][36], occ[66];

void del(int id)
{
    if (--occ[c[id]] == 0) --cnt;
}

void add(int id)
{
    if (occ[c[id]]++ == 0) ++cnt;
}

void C(int l, int r)
{
    while(L < l) del(L++);
    while(L > l) add(--L);
    while(R < r) add(++R);
    while(R > r) del(R--);
}

void compute(int g, int l, int r, int optl, int optr)
{
    if (l > r) return;
    int m = (l + r) >> 1, bestID = -1;
    for(int k=optl; k<=min(optr, m); k++)
    {
        C(k, m);
        if (dp[m][g] < dp[k - 1][g - 1] + cnt)
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
    cin >> N >> G;
    for(int i=1; i<=N; i++)
    {
        cin >> c[i];
    }

    set0(dp), set0(occ);
    for(int i=1; i<=N; i++)
    {
        C(1, i);
        dp[i][1] = cnt;
    }

    for(int g=1; g<=G; g++)
    {
        compute(g, g, N, 1, N);
    }
    cout << dp[N][G];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
