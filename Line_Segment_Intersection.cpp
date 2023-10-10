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

struct point
{
    ll x, y;
    point(ll a = 0, ll b = 0) : x(a), y(b)
    {
    }

    point operator - (const point &v)
    {
        return point(x - v.x, y - v.y);
    }

    point operator + (const point &v)
    {
        return point(x + v.x, y + v.y);
    }

    ll operator * (const point &v)
    {
        return x * v.x + y * v.y;
    }

    ll operator ^ (const point &v)
    {
        return x * v.x - y * v.y;
    }
}a, b, c, d;

int tc;

void solve()
{
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    cout << ((a - c) * (a - d)) * ((b - c) * (b - d));
//    if (((a - c) * (a - d)) * ((b - c) * (b - d)) > 0)
//    {
//        cout << "none";
//    }
//    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif //SKY
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
