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

int X, Y, Z;

ll ck(ll T)
{
    ll cur = T * Y, must = 0;
    for(int i=1; i<=Z; i++)
    {
        cur += Y;
        must += X;
        if (must > cur) return false;
    }
    return true;
}

void solve()
{
    cin >> X >> Y >> Z;
    ll l = 0, r = 1e10, ans = 0;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (ck(m))
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
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
