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

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

ll x, y;

ld S(ld a, ld b, ld c)
{
    if (a + b <= c || a + c <= b || b + c <= a) return 0;
    a = (ld)a, b = (ld)b, c = (ld)c;
    ld p = (a + b + c) / (ld)2;
    return (ld)sqrt(p * (p - a) * (p - b) * (p - c));
}

void solve()
{
    cin >> x >> y;
    if (x > y) swap(x, y);
    if (x == y) cout << 2 * x - 1;
     else cout << (S(x, x, y) <= S(x, y, y) ? y : x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
