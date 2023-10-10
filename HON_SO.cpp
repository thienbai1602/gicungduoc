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
const int mxN = 1e6 + 66;

ll a, b, c, A, B, C, mx = -inf;

void cal(ll a, ll b, ll c)
{
    if (c == 0) return;
    if ((a * c + b) / (ld)c > mx)
    {
        mx = (a * c + b) / (ld)c;
        A = a, B = b, C = c;
    }
}

void solve()
{
    cin >> a >> b >> c;
    cal(a, b,c);
    cal(a, c, b);
    cal(b, a, c);
    cal(b, c, a);
    cal(c, a, b);
    cal(c, b, a);
    if (mx == -inf) cout << -1;
     else cout << A << " " << B << " " << C;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
