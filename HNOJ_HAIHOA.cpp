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
const int mxN = 2e3 + 66;

int n, K;
ll a[mxN][mxN], pref[mxN][mxN];

void solve()
{
    cin >> n >> K;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            ll u, v, x;
            cin >> x;
            u = i - j + n, v = i + j;
            a[u][v] = x;
        }
    }

    set0(pref);
    for(int i=1; i<=2*n; i++)
    {
        for(int j=1; j<=2*n; j++)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int lu, lv, ru, rv;;
            lu = max(0, i - j + n - K - 1), lv = max(0, i + j - K - 1);
            ru = min(2*n, i - j + n + K), rv = min(2*n, i + j + K);
            cout << pref[ru][rv] - pref[lu][rv] - pref[ru][lv] + pref[lu][lv] << (j < n ? " " : "\n");
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
