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
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 5e5 + 66;

int n;
ll a[mxN], p[mxN], T[mxN];

void solve()
{
    cin >> n;
    set0(p), set0(T);
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        T[i] = (T[i - 1] + a[i]) % 3;
        p[i] = (p[i - 1] + a[i] * T[i - 1]) % 3;
    }

    vector<vector<ll>> dp(3, vector<ll>(3, 0));
    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        ++dp[T[i - 1]][p[i - 1]];
        for(ll x=0; x<3; x++)
        {
            for(ll y=0; y<3; y++)
            {
                if ((p[i] - y - (T[i] - x) * x + 9) % 3 == 0)
                {
                    ans += dp[x][y];
                }
            }
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
