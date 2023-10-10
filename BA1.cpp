#include    <bits/stdc++.h>
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define ii pair<ld, ld>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

const ld INF = 1e12;

ii dog, house[4];
ll a, b, c, d;

ld sq(ld x)
{
    return x * x;
}

ld dist(ii z, ii t)
{
    return (ld)sqrt((ld)sq(z.fi - t.fi) + (ld)sq(z.se - t.se));
}

void solve()
{
    cin >> dog.fi >> dog.se;
    cin >> a >> b >> c >> d;
    house[0] = mp(a, b);
    house[1] = mp(a, d);
    house[2] = mp(c, d);
    house[3] = mp(c, b);

    ld ans = INF * 1.0f;
    if (dog.fi >= a && dog.fi <= c)
    {
        ld tp = min(abs(dog.se - b), abs(dog.se - d));
        ans = min(ans, tp);
        cout << fixed << setprecision(1) << ans;
        return;
    }

    if (dog.se >= b && dog.se <= d)
    {
        ld tp = min(abs((ld)dog.fi - a), abs((ld)dog.fi - c));
        ans = min(ans, tp);
        cout << fixed << setprecision(1) << ans;
        return;
    }

    for(int i=0; i<4; i++)
    {
        ans = min(ans, dist(dog, house[i]));
        //cout << house[i].fi << " " << house[i].se << " " << ans <<  "\n";
    }
    cout << fixed << setprecision(1) << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
