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
const int mxN = 5e5 + 66;

int N;
ll pref[mxN];
ii paint[mxN];

void solve()
{
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cin >> paint[i].fi >> paint[i].se;
    }
    sort(paint + 1, paint + 1 + N);

    set0(pref);
    for(int i=1; i<=N; i++)
    {
        pref[i] = pref[i - 1] + paint[i].se;
    }

    ll ans = -inf, mx = paint[1].fi;
    for(int i=1; i<=N; i++)
    {
        ans = max(ans, (pref[i] - paint[i].fi) + mx);
        mx = max(mx, (paint[i].fi - pref[i - 1]));
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
