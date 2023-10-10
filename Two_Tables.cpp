#include    <bits/stdc++.h>
#define SKY
#define ll long long
#define ld long double
#define MASK(x) (1LL << x)
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

int tc;
ll W, H, wid, hei, x, y, z, t;

ll left_side()
{
    ll width_table = z - x;
    if (width_table + wid > W) return inf;
    if (x >= wid) return 0;
     else return abs(wid - x);
}

ll right_side()
{
    ll width_table = z - x;
    if (width_table + wid > W) return inf;
    if ((W - z) >= wid) return 0;
     else return abs(z - (W - wid));
}

ll top_side()
{
    ll height_table = t - y;
    if (height_table + hei > H) return inf;
    if ((H - t) >= hei) return 0;
     else return abs(t - (H - hei));
}

ll bottom_side()
{
    ll height_table = t - y;
    if (height_table + hei > H) return inf;
    if (y >= hei) return 0;
     else return abs(y - hei);
}

void solve()
{
    cin >> W >> H >> x >> y >> z >> t >> wid >> hei;
    ll width = min(left_side(), right_side());
    ll height = min(top_side(), bottom_side());
    if (min(width, height) == inf)
    {
        cout << -1 << "\n";
    } else
    {
        cout << fixed << setprecision(6) << min(width, height) * 1.0f << "\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif //SKY
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
