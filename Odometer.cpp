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

const int M = 55;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

ll l, r, dp[20][M][2][2];

ll recur(vector<int> &num, int N, int k, int tar1, int tar2, bool leading, bool tight)
{
    if (N == 0)
    {
        if (leading) return 0;
        if (tar2 == -1) return (k >= 20);
         else return (k == 20);
    }

    if (dp[N][k][leading][tight] != -1) return dp[N][k][leading][tight];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        bool is_leading = leading && (digit == 0);
        if (!is_leading && tar2 != -1 && digit != tar1 && digit != tar2) continue;
        int pl = (!is_leading ? (tar1 == digit ? 1 : -1) : 0);
        ans += recur(num, N - 1, k + pl, tar1, tar2, is_leading, tight && (digit == limit));
    }
    return dp[N][k][leading][tight] = ans;
}

ll sol(ll X)
{
    vector<int> num;
    while(X > 0)
    {
        num.pb(X % 10);
        X /= 10;
    }
    reverse(all(num));

    ll ret = 0;
    for(int tar=0; tar<=9; tar++)
    {
        memset(dp, -1, sizeof(dp));
        ret += recur(num, sz(num), 20, tar, -1, 1, 1);
    }

    for(int tar1=0; tar1<=9; tar1++)
    {
        for(int tar2=tar1+1; tar2<=9; tar2++)
        {
            memset(dp, -1, sizeof(dp));
            ret -= recur(num, sz(num), 20, tar1, tar2, 1, 1);
        }
    }
    return ret;
}

void solve()
{
    cin >> l >> r;
    cout << sol(r) - sol(l - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("odometer.in", "r", stdin);
    freopen("odometer.out", "w", stdout);
    solve();
    return 0;
}
