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
#define X real()
#define Y imag()
#define point complex<ll>
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

int N;

void solve()
{
    vector<point> arr;
    for(int i=0; i<N; i++)
    {
        ll x, y;
        cin >> x >> y;
        arr.pb({x, y});
    }
    arr.pb(arr[0]);

    ld ans = 0;
    for(int i=0; i<N; i++)
    {
        ans += (arr[i].X * arr[i + 1].Y - arr[i].Y * arr[i + 1].X);
    }
    cout << (ans > 0 ? "CCW " : "CW " ) << fixed << setprecision(1) << abs(ans) / (ld)2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif //SKY
    while(cin >> N)
    {
        if (N == 0) break;
        solve();
    }
    return 0;
}
