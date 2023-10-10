#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;

struct rect
{
    ii coord[2];
}sq[2];

ll sqr(ll x)
{
    return x * x;
}

void solve()
{
    cin >> sq[0].coord[0].fi >> sq[0].coord[0].se >> sq[0].coord[1].fi >> sq[0].coord[1].se;
    cin >> sq[1].coord[0].fi >> sq[1].coord[0].se >> sq[1].coord[1].fi >> sq[1].coord[1].se;
    ll x1 = min(sq[0].coord[0].fi, sq[1].coord[0].fi);
    ll x2 = max(sq[0].coord[1].fi, sq[1].coord[1].fi);
    ll y1 = min(sq[0].coord[0].se, sq[1].coord[0].se);
    ll y2 = max(sq[0].coord[1].se, sq[1].coord[1].se);
    cout << max(sqr(x2 - x1), sqr(y2 - y1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    solve();
    return 0;
}
