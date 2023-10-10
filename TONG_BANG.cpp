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
const ll MOD = 1532023;
const ll MODV = MOD * 2;
const int mxN = 1e6 + 66;

ll M, N;

void solve()
{
    cin >> N >> M;
    ll oddN = (N + 1) / 2 % MOD, evenN = N / 2 % MOD;
    ll oddM = (M + 1) / 2 % MOD, evenM = M / 2 % MOD;

    //cout << evenN << " " << evenM << "\n";

    ll ScolM = ((((2 + (oddN - 1) % MODV * (M * 2)) % MODV) * oddN / 2) % MOD * (oddM % MOD)) % MOD;
    ll bs = (((2 + (oddM  - 1) * 2) % MODV * (oddM - 1) / 2) % MOD * (oddN % MOD)) % MOD;
    //cout << ScolM << " " << bs << "\n";

    ll Scolu = ((((M + 2) * 2 + (evenN - 1) % MOD * (M * 2)) % MODV) * evenN / 2) % MOD * (evenM % MOD) % MOD;
    ll slu2 = (((2 + (evenM - 1) * 2) % MODV * (evenM - 1) / 2) % MOD * (evenN % MOD)) % MOD;
    //cout << Scolu << " " << slu2 << "\n";
    cout << ((ScolM + bs) % MOD + (Scolu + slu2) % MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
