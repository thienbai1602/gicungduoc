#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;

struct rect
{
    ii coord[2];

    ll area()
    {
        return (coord[1].fi - coord[0].fi) * (coord[1].se - coord[0].se);
    }

    ll inter(rect& v)
    {
        ll mx = max(min(coord[1].fi, v.coord[1].fi) - max(coord[0].fi, v.coord[0].fi), 1LL * 0);
        ll my = max(min(coord[1].se, v.coord[1].se) - max(coord[0].se, v.coord[0].se), 1LL * 0);
        return mx * my;
    }
}a, b, c;

void solve()
{
    cin >> a.coord[0].fi >> a.coord[0].se >> a.coord[1].fi >> a.coord[1].se;
    cin >> b.coord[0].fi >> b.coord[0].se >> b.coord[1].fi >> b.coord[1].se;
    cin >> c.coord[0].fi >> c.coord[0].se >> c.coord[1].fi >> c.coord[1].se;

    ll ret = a.area() + b.area();
    cout << ret - a.inter(c) - b.inter(c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    solve();
    return 0;
}
