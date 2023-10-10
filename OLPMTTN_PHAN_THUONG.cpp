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

const int mxN = 1e5 + 66;

ll n, S;
vector<ii> cur, sp;

void solve()
{
    cin >> n >> S;
    ll t = 0, cur_S = 0;
    for(int i=0; i<n; i++)
    {
        ll w, v, c;
        cin >> w >> v >> c;
        if (c == 1)
        {
            cur.pb(mp(w, v));
            t += v;
            cur_S += w;
        } else sp.pb(mp(w, v));
    }

    sort(all(cur)); sort(all(sp));

    set<ll> store;
    ll ans = t, pos = 0;
    for(int i=0; i<sz(cur); i++)
    {
        while(pos < sz(sp) && S - cur_S + cur[i].fi >= sp[pos].fi)
        {
            store.insert((sp[pos++].se));
        }
        if (!store.empty()) ans = max(ans, t - cur[i].se + *store.rbegin());
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
