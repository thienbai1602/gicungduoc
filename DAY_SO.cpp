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
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int n, Q;
ll sz[mxN], p[mxN];

int findp(int u)
{
    if (u == p[u]) return u;
     else return p[u] = findp(p[u]);
}

void Union(int a, int b)
{
    a = findp(a), b = findp(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
}

ll get(int a)
{
    return sz[findp(a)];
}

void solve()
{
    cin >> n >> Q;
    vector<ii> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }

    vector<ii> listID(Q);
    for(int i=0; i<Q; i++)
    {
        cin >> listID[i].fi;
        listID[i].se = i;
    }

    sort(all(a));
    sort(all(listID));
    for(int i=1; i<=n; i++)
    {
        sz[i] = 1, p[i] = i;
    }

    ll mx = 0, r = 0;
    vector<ll> ans(Q);
    vector<bool> vis(n + 1, false);
    for(int i=0; i<Q; i++)
    {
        while(r < n && a[r].fi <= listID[i].fi)
        {
            vis[a[r].se + 1] = true;
            if (a[r].se > 0 && vis[a[r].se])
            {
                Union(a[r].se, a[r].se + 1);
            }

            if (a[r].se + 2 <= n && vis[a[r].se + 2])
            {
                Union(a[r].se + 1, a[r].se + 2);
            }
            mx = max(mx, get(a[r].se + 1));
            ++r;
        }
        ans[listID[i].se] = mx;
    }
    for(ll &x : ans) cout << x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
