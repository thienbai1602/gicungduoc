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
const int mxN = 1e6 + 66;

ll a1, b1, a2, b2, a3, b3;

void solve()
{
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    // z = x * y;
    // +) Xet y => sqrt(z) -> x <= sqrt(z);
    ll ans = 0;
    ll sqr = sqrt(b3);
    for(ll x=a1; x<=min(sqr, b1); x++)
    {
        if (x == 0)
        {
            if (0 >= a3 && 0 <= b3) ans += (b2 - a2 + 1);
            continue;
        }
        ll idTop = min(b3 / x, b2);
        ll idBottom = max((a3 / x + (a3 % x > 0)), a2);
        //cout << x << " " << idTop << " " << idBottom << "\n";
        ans += max(0LL, idTop - idBottom + 1);
    }

    //cout << "\n";

    // +) Xet y < sqrt(z) -> x > sqrt(z);
    ll sq = (sqr * sqr == b3 ? sqr - 1 : sqr);
    for(ll y=a2; y<=min(sq, b2); y++)
    {
        if (y == 0)
        {
            if (0 >= a3 && 0 <= b3) ans += (b1 - a1 + 1);
            continue;
        }
        ll idTop = min(b3 / y, b1);
        ll idBottom = max({(a3 / y + (a3 % y > 0)), a1, sqr + 1});
        //cout << y << " " << idTop << " " << idBottom << "\n";
        ans += max(0LL, idTop - idBottom + 1);
    }
    cout << ans - (a1 * b1 <= 0 && a2 * b2 <= 0 && a3 * b3 <= 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
