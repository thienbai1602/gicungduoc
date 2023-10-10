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
const int mxN = 1e6 + 66;

int n;
vector<ll> a, pref;

void solve()
{
    cin >> n;
    a.assign(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    pref.assign(n, 0);
    pref[0] = a[0];
    for(int i=1; i<n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    int l = 0, r = -1;
    ll ans = inf, S = pref[n - 1];
    while(r < n - 1)
    {
        while(r < n - 1 && pref[r + 1] - (l == 0 ? 0 : pref[l - 1]) <= S/2)
        {
            ++r;
        }
        ans = min(ans, abs(S - 2 * (pref[r] - (l == 0 ? 0 : pref[l - 1]))));
        if (r < n - 1)
        {
            ans = min(ans, abs(S - 2 * (pref[r + 1] - (l == 0 ? 0 : pref[l - 1]))));
        }
        ++l;
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
