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
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int tc, n;

void solve()
{
    cin >> n;
    vector<int> a(n + 1);
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    // a[i] = (i + j) / a[j] (i < j)
    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        int j = a[i] - i;
        for(; j<=n; j+=a[i])
        {
            if (j <= i) continue;
            if (a[i] * a[j] == i + j) ++ans;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
