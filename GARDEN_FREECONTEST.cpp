#include    <bits/stdc++.h>
#define ll unsigned long long
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

int n;
ll L;
vector<ii> tree;

bool ck(ll X)
{
    long long cur = L;
    for(int i=0; i<n; i++)
    {
        if (tree[i].fi >= X) continue;
        ll diff = X - tree[i].fi;
        cur -= (diff + tree[i].se - 1) / tree[i].se;
        if (cur < 0) return false;
    }
    return cur >= 0;
}

void solve()
{
    cin >> n >> L;
    tree.assign(n, mp(0, 0));
    for(int i=0; i<n; i++)
    {
        cin >> tree[i].fi >> tree[i].se;
    }

    ll l = 1, r = 1e18, ans = 0;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (ck(m))
        {
            ans = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
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
