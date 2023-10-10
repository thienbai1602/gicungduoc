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
const int mxN = 56;

int tc;
ll n, k, fa[mxN], f[mxN];

void solve()
{
    fa[0] = 1, fa[1] = 0;
    for(int i=2; i<=46; i++)
    {
        fa[i] = fa[i - 2] + fa[i - 1];
    }

    f[0] = f[1] = 1;
    for(int i=2; i<=46; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
}

ll sol(ll n, ll k)
{
    if (n < 2) return (n == 0 && k == 1);
    if (n < 0 || k <= 0) return 0;
    if (f[n - 2] <= k) return (n - 2 < 0 ? 0 : fa[n - 2]) + sol(n - 1, k - f[n - 2]);
     else return sol(n - 2, k);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    cin >> tc;
    while(tc--)
    {
        cin >> n >> k;
        cout << sol(n, k) << "\n";
    }
    return 0;
}
