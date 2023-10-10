#include    <bits/stdc++.h>
#define ll long long
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

int N, cnt[mxN];
vector<ii> store;

ll dist(ii a, ii b)
{
    return (ll)max(abs(a.fi - b.fi), abs(a.se - b.se));
}

void solve()
{
    cin >> N;
    vector<pair<ii, int>> coord;
    for(int i=0; i<N; i++)
    {
        ll x, y;
        cin >> x >> y;
        coord.pb(mp(mp(x, y), i));
    }

    set0(cnt);
    sort(all(coord));
    for(int i=0; i<N; i++)
    {
        if (!cnt[coord[i].se] && (i < 2 || i >= N - 2))
        {
            store.pb(coord[i].fi);
            ++cnt[coord[i].se];
        }
    }

    sort(all(coord), [&](pair<ii, int> &a, pair<ii, int> &b){return a.fi.se < b.fi.se || (a.fi.se == b.fi.se && a.fi.fi < b.fi.fi);});
    for(int i=0; i<N; i++)
    {
        if (!cnt[coord[i].se] && (i < 2 || i >= N - 2))
        {
            store.pb(coord[i].fi);
            ++cnt[coord[i].se];
        }
    }

    vector<ll> ans;
    for(int i=0; i<sz(store); i++)
    {
        for(int j=i+1; j<sz(store); j++)
        {
            ans.pb(dist(store[i], store[j]));
        }
    }
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    cout << ans[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
