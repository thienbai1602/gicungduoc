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

struct rect
{
    ll x, y, z, t;
    rect(ll a, ll b, ll c, ll d) : x(a), y(b), z(c), t(d)
    {
    }

    ll area()
    {
        return (z - x) * (t - y);
    }

    ll inter(const rect &v)
    {
        ll xOverlap = min(z, v.z) - max(x, v.x);
        ll yOverlap = min(t, v.t) - max(y, v.y);
        return xOverlap * yOverlap;
    }

    bool cover(ll u, ll v)
    {
        return (x <= u && u <= z && y <= v && v <= t);
    }
};

void solve()
{
    vector<rect> rectangular;
    for(int i=0; i<2; i++)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        rectangular.pb(rect(a, b, c, d));
    }

    int num_corner = 0;
    if (rectangular[1].cover(rectangular[0].x, rectangular[0].y)) num_corner++;
    if (rectangular[1].cover(rectangular[0].x, rectangular[0].t)) num_corner++;
    if (rectangular[1].cover(rectangular[0].z, rectangular[0].y)) num_corner++;
    if (rectangular[1].cover(rectangular[0].z, rectangular[0].t)) num_corner++;

    if (num_corner < 2)
    {
        cout << rectangular[0].area();
    } else
    {
        if (num_corner == 4)
        {
            cout << 0;
        } else
        {
            cout << rectangular[0].area() - rectangular[0].inter(rectangular[1]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    #endif //SKY
    solve();
    return 0;
}
