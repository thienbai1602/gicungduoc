#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int n;
ll a[mxN];

void solve()
{
    cin >> n;
    ll mx = -INF, mi = INF;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        mi = min(mi, a[i]);
    }

    vector<int> maxx, minn;
    for(int i=0; i<n; i++)
    {
        if (a[i] == mi) minn.pb(i);
        if (a[i] == mx) maxx.pb(i);
    }

    ll ans = INF;
    for(int x : minn)
    {
        int ps = lower_bound(all(maxx), x) - maxx.begin();
        if (ps < sz(maxx)) ans = min(ans, (ll)abs(x - maxx[ps]) + 1);
        ps--;
        if (ps >= 0) ans = min(ans, (ll)abs(x - maxx[ps]) + 1);
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


