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
const int mxN = 3e4 + 66;

int n;
ll h[mxN], pref[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> h[i];
        pref[i] = (i == 0 ? h[i] : pref[i - 1] + h[i]);
    }

    ll ans = 0;
    for(int i=0; i<n-1; i++)
    {
        ans += (h[i] * (pref[n - 1] - pref[i]));
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
