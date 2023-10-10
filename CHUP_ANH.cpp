#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

const ll INF = 1e18;
const int mxN = 1e5 + 66;

int n, m;
ll x[mxN], y[mxN], pref[mxN];
vector<ii> beautiful;

void solve()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        ll u, v;
        cin >> u >> v;
        beautiful.pb(mp(u, v));
    }

    sort(all(beautiful));
    for(int i=0; i<n; i++)
    {
        pref[i] = (i == 0 ? beautiful[i].se : pref[i - 1] + beautiful[i].se);
    }

    for(int i=0; i<m; i++)
    {
        cin >> x[i];
    }

    for(int i=0; i<m; i++)
    {
        cin >> y[i];
    }

    for(int i=0; i<m; i++)
    {
        ll ans = 0;
        auto it = upper_bound(all(beautiful), mp(x[i], INF));
        if (it != beautiful.begin())
        {
            ll ps = it - beautiful.begin() - 1;
            ans += pref[ps];
        }

        it = upper_bound(all(beautiful), mp(y[i], INF));
        if (it != beautiful.begin())
        {
            ll ps = it - beautiful.begin() - 1;
            ans += pref[ps];
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
