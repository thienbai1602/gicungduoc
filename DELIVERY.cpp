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
const int mxN = 1e5 + 66;

int n, m;

void solve()
{
    cin >> n >> m;
    vector<ll> neg, pos;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        if (x < 0) neg.pb(x);
         else pos.pb(x);
    }

    sort(all(neg));
    sort(rall(pos));

    ll ans = 0;
    for(int i=0; i<sz(neg); i++)
    {
        if (i % m == 0)
        {
            ans += abs(neg[i] * 2);
        }
    }

    for(int i=0; i<sz(pos); i++)
    {
        if (i % m == 0)
        {
            ans += pos[i] * 2;
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
