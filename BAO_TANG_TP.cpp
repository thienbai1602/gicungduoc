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
const int mxN = 5e5 + 66;

int n;
ii pic[mxN];
ll pref[mxN], u[mxN];

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> pic[i].fi >> pic[i].se;
    }
    sort(pic + 1, pic + 1 + n);

    set0(pref), set0(u);
    for(int i=1; i<=n; i++)
    {
        pref[i] = pref[i - 1] + pic[i].se;
    }

    u[1] = pic[1].fi;
    for(int i=2; i<=n; i++)
    {
        u[i] = max(u[i - 1], pic[i].fi - pref[i - 1]);
    }

    // H = S - (Amax - Amin) = pref[j] - pref[i - 1] - A[j] + A[i];
    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        ans = max(ans, (pref[i] - pic[i].fi) + u[i]);
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
