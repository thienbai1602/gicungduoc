#include    <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

pair<ll, ll> x, y, z, t;

void solve()
{
    cin >> x.fi >> x.se >> y.fi >> y.se >> z.fi >> z.se >> t.fi >> t.se;
    if (x.fi > y.fi) swap(x.fi, y.fi);
    if (x.se > y.se) swap(x.se, y.se);
    if (z.fi > t.fi) swap(z.fi, t.fi);
    if (z.se > t.se) swap(z.se, t.se);

    //cout << x.fi << " " << x.se << " " << y.fi << " " << y.se << " " << z.fi << " " << z.se << " " << t.fi << " " << t.se << "\n";

    pair<ll, ll> a, b;
    a.fi = max(x.fi, z.fi), a.se = min(y.fi, t.fi);
    b.fi = max(x.se, z.se), b.se = min(y.se, t.se);

    ll ret = 0;
    if (a.fi <= a.se && b.fi <= b.se)
        ret = max(ret, (a.se - a.fi) * (b.se - b.fi));
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
