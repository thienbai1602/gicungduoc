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
const int mxN = 2e5 + 66;

int tc, n;

void solve()
{
    cin >> n;
    vector<ii> seg(n);
    vector<ll> L(n), R(n);
    for(int i=0; i<n; i++)
    {
        cin >> L[i] >> R[i];
        seg[i] = mp(L[i], R[i]);
    }

    sort(all(L)), sort(all(R));
    int ans = n - 1;
    for(int i=0; i<n; i++)
    {
        int left = lower_bound(all(R), seg[i].fi) - R.begin();
        int right = n - (upper_bound(all(L), seg[i].se) - L.begin());
        ans = min(ans, left + right);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
