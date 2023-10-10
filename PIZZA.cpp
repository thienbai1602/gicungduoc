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

vector<ll> a;

void solve()
{
    a.assign(12, 0);
    for(int i=0; i<8; i++)
    {
        cin >> a[i];
    }

    for(int i=8; i<11; i++)
    {
        a[i] = a[i - 8];
    }

    ll ans = 0;
    for(int i=0; i<=4; i++)
    {
        ll S = 0;
        for(int j=0; j<4; j++)
        {
            S += a[i + j];
        }
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
