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
const int mxN = 1e6 + 66;

int n, q, p;
ll a[mxN], pref[mxN];

void solve()
{
    cin >> n >> q >> p;
    set0(a);
    while(q--)
    {
        ll l, r, v;
        cin >> l >> r >> v;
        a[l] += v, a[r + 1] -= v;
    }

    for(int i=1; i<=n; i++)
    {
        a[i] += a[i - 1];
    }

    set0(pref);
    for(int i=1; i<=n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    while(p--)
    {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("SLR.INP", "r", stdin);
    freopen("SLR.OUT", "w", stdout);
    solve();
    return 0;
}
