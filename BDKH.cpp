#include    <bits/stdc++.h>
//#define SKY
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
const int mxN = 1e6 + 66;

int n, m;

void solve()
{
    cin >> n >> m;
    vector<ll> p(n);
    for(int i=0; i<n; i++)
    {
        cin >> p[i];
    }

    vector<ll> ans(n, 0);
    for(int i=0; i<m; i++)
    {
        ll L, R, X;
        cin >> L >> R >> X;
        for(int j=0; j<sz(p); j++)
        {
            ll x = p[j];
            if (x >= L && x <= R)
            {
                ans[j] += X * ((x - L) & 1 ? -1 : 1);
            }
        }
    }
    for(ll &x : ans) cout << x << "\n";
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
