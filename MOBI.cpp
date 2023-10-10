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

int n, K;
ll coord[mxN];

void solve()
{
    set0(coord);
    cin >> n >> K;
    for(int i=0; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        coord[x] += y;
    }

    ll ans = 0;
    for(ll x=0, S=0; x<=(ll)1e6; x++)
    {
        S += coord[x];
        S -= (x <= 2 * K ? 0 : coord[x - 2 * K - 1]);
        ans = max(ans, S);
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
