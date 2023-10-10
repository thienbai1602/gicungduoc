#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int n;
ll cnt[mxN], pref[mxN];

ll ck(ll k, ll n)
{
    if (k > n) return 0;
    ll ret = 1, g = 1;
    for(ll x=n-k+1, ct=1; x<=n; x++, ct++)
    {
        ret *= x;
        g *= ct;
    }
    return ret / g;
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        ++cnt[x];
    }

    for(int i=1; i<=(ll)1e6; i++)
    {
        pref[i] = pref[i - 1] + cnt[i];
    }

    unsigned ll ans = 0;
    for(int x=1; x<=(ll)1e6; x++)
    {
        ans += ck(2, cnt[x]) * (pref[2 * x - 1] - cnt[x]) + ck(3, cnt[x]);
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


