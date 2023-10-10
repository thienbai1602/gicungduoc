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
const int mxN = 500 + 66;

int N;
ll a[mxN][mxN], pref[mxN][mxN];

void solve()
{
    cin >> N;
    for(int row=1; row<=N; row++)
    {
        for(int col=1; col<=N; col++)
        {
            cin >> a[row][col];
        }
    }

    set0(pref);
    for(int row=1; row<=N; row++)
    {
        for(int col=1; col<=N; col++)
        {
            pref[row][col] = pref[row - 1][col] + pref[row][col - 1] - pref[row - 1][col - 1] + a[row][col];
        }
    }

    ll ans = INF;
    for(int row=1; row<=N; row++)
    {
        for(int col=1; col<=N; col++)
        {
            ll x = pref[row][col], y = pref[N][col] - pref[row][col];
            ll z = pref[N][N] - pref[N][col] - pref[row][N] + pref[row][col], t = pref[row][N] - pref[row][col];
            ll mx = max({x, y, z, t}), mi = min({x, y, z, t});
            ans = min(ans, mx - mi);
        }
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

