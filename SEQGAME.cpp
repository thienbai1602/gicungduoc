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
const int mxN = 1e3 + 66;

ll n, D, a[mxN], pref[mxN], suf[mxN];

ll S(ll x, ll y, ll sl)
{
    return (x + y) * sl / 2;
}

void solve()
{
    cin >> n >> D;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    set0(pref), set0(suf);
    for(int i=1; i<=n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    for(int i=n; i>0; i--)
    {
        suf[i] = suf[i + 1] + a[i];
    }

    ll ans = INF;
    for(int i=1; i<=n; i++)
    {
        ll nxt = 0;
        ll st = a[i] - (i - 1) * D;
        for(int j=1; j<=n; j++, st+=D)
        {
            nxt += abs(a[j] - st);
        }
        ans = min(ans, nxt);
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
