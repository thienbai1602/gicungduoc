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
const ll inf = 1e18;
const int block = 800;
const ll MOD = 1e9 + 7;
const int mxN = 2e5 + 66;

int n, Q;
ll a[mxN], S[block + 1];

void upd(int k, ll x)
{
    S[k / block] -= (a[k] - x);
    a[k] = x;
}

ll get(int r)
{
    ll ans = 0;
    for(int id=0; id<r/block; id++)
    {
        ans += S[id];
    }

    for(int i=(r/block)*block; i<=r; i++)
    {
        ans += a[i];
    }
    return ans;
}

void solve()
{
    cin >> n >> Q;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        S[i / block] += a[i];
    }

    while(Q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll k, u;
            cin >> k >> u;
            --k;
            upd(k, u);
        } else
        {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << get(r) - get(l - 1) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
