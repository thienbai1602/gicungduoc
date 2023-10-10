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

int n, m;

void solve()
{
    cin >> n >> m;
    vector<ll> x(n), y(m);
    ll Sx = 0, Sy = 0;
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
        Sx += x[i];
    }

    for(int i=0; i<m; i++)
    {
        cin >> y[i];
        Sy += y[i];
    }

    sort(all(x)), sort(all(y));

    Sx %= MOD, Sy %= MOD;
    ll nxt = 0;
    for(int i=0; i<m-1; i++)
    {
        Sy -= y[i];
        nxt = (nxt + Sy - (m - i - 1) * y[i] + MOD * MOD) % MOD;
    }

    ll ans = 0;
    for(int i=0; i<n-1; i++)
    {
        Sx -= x[i];
        (ans += ((Sx - (n - i - 1) * x[i] + MOD * MOD) % MOD * (nxt % MOD))) %= MOD;
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
