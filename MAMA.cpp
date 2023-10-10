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
const ll MOD = 1e9;
const int mxN = 1e5 + 66;

int n;
ll a[mxN];
ii fen[mxN];
vector<ll> seg;

ii operator + (ii a, ii b)
{
    return mp((a.fi + b.fi) % MOD, a.se + b.se);
}

ii operator - (ii a, ii b)
{
    return mp((a.fi - b.fi + MOD * MOD) % MOD, a.se - b.se);
}

int find_k(ll x)
{
    return upper_bound(all(seg), x) - seg.begin();
}

void upd(int id, ll x)
{
    for(; id<=n; id+=(id & -id))
    {
        fen[id] = fen[id] + mp(x, 1);
    }
}

ii get(int id)
{
    ii ans = mp(0, 0);
    for(; id>0; id-=(id & -id))
    {
        ans = ans + fen[id];
    }
    return ans;
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        seg.pb(a[i]);
    }

    sort(all(seg));
    seg.erase(unique(all(seg)), seg.end());

    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        int index = find_k(a[i]);
        //cout << index << "\n";
        ii nxt = get(n) - get(index);
        int ps = nxt.fi, sz = nxt.se;
        ll tp = (sz == 0 ? 0 : (ps - a[i] * sz + MOD * MOD)) % MOD;
        //cout << ps << " " << sz << " " << tp << "\n";
        ans = (ans + tp) % MOD;
        upd(index, a[i]);
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
