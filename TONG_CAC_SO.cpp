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
const ll MOD = 20192020;
const ll MODV = 20192020 * 2;
const int mxN = 1e6 + 66;

ll N, M, K, ans = 0;

ll sum(ll a, ll d, ll sz)
{
    // S = (2 * u1 + (sz - 1) * d) * sz / 2
    return (((2 * a + (sz - 1) * d) % MODV) * (sz % MODV)) % MODV / 2 % MOD;
}

void solve()
{
    cin >> N >> M >> K;
    ll ans = (((sum(N * M, N, K) % MOD) * (K % MOD)) % MOD + ((sum(M, 1, K) % MOD) * ((K - 1) * K / 2 % MOD)) % MOD) % MOD;
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
