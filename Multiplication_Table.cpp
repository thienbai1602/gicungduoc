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
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

ll N, M, K;

ll calc(ll X)
{
    ll ret = 0;
    for(ll x=1; x<=min(N, X); x++)
    {
        ret += min(M, X / x);
    }
    return ret;
}

ll bs(ll l, ll r)
{
    ll ans = -1;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (calc(m) >= K)
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> N >> M >> K;
    if (N > M) swap(N, M);
    cout << bs(1, N * M);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
