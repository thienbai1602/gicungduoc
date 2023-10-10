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
const int mxN = 2e5 + 66;

int n;
ll a[mxN], pref[mxN];

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);

    set0(pref);
    for(int i=1; i<=n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    ll ans = 0;
    for(int i=2; i<=n; i++)
    {
        ans += (a[i] * (i - 1)) - pref[i - 1];
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