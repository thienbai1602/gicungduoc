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

int n, k, sz = 0;
map<ll, ll> store;
ll pw[66], a[mxN], pref[mxN];

void solve()
{
    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<n; i++)
    {
        pref[i] = (i == 0 ? a[i] : a[i] + pref[i - 1]);
    }

    if (abs(k) != 1)
    {
        ll cur = 1;
        pw[0] = cur;
        while(abs(cur) <= (ll)2e14)
        {
            cur *= k;
            pw[++sz] = cur;
        }
    } else
    {
        sz = (k == -1 ? 2 : 1);
        pw[0] = k, pw[1] = k * k;
    }

    ll ans = 0;
    store[0] = 1;
    for(int i=0; i<n; i++)
    {
        for(int p=0; p<sz; p++)
        {
            ans += store[pref[i] - pw[p]];
        }
        ++store[pref[i]];
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
