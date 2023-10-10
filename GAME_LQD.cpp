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

const ll base = 10;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

vector<ll> rem[10];
ll N, K, q[11];

void init()
{
    rem[1].pb(1);
    rem[2].pb(2), rem[2].pb(4), rem[2].pb(8), rem[2].pb(6);
    rem[3].pb(3), rem[3].pb(9), rem[3].pb(7), rem[3].pb(1);
    rem[4].pb(4), rem[4].pb(6);
    rem[5].pb(5);
    rem[6].pb(6);
    rem[7].pb(7), rem[7].pb(9), rem[7].pb(3), rem[7].pb(1);
    rem[8].pb(8), rem[8].pb(4), rem[8].pb(2), rem[8].pb(6);
    rem[9].pb(9), rem[9].pb(1);
}

ll pw(ll a, ll b, ll m)
{
    ll ret = 1;
    while(b)
    {
        if (b & 1) ret = ((ret % m) * (a % m)) % m;
        a = ((a % m) * (a % m)) % m;
        b >>= 1;
    }
    return ret;
}

void solve()
{
    cin >> K >> N;
    for(ll r=1; r<10; r++)
    {
        q[r] = ((N / 10) + (N % 10 >= r)) % base;
    }

    ll ans = 0;
    for(ll r=1; r<10; r++)
    {
        ll mul = pw(2, pw(2, K - 1, 2), 4);
        ll nxt = max(0LL, mul % sz(rem[r]) - 1);
        ans = (ans + rem[r][nxt] * q[r]) % base;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    init(); solve();
    return 0;
}
