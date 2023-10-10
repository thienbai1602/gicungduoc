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

int n;
ll a[mxN], sz[mxN], p[mxN], per[mxN];

int findp(int u)
{
    if (u == p[u]) return u;
     else return p[u] = findp(p[u]);
}

void Union(int a, int b)
{
    a = findp(a), b = findp(b);
    if (a == b) return;
    sz[a] += sz[b];
    p[b] = a;
}

ll get(int a)
{
    return sz[findp(a)];
}

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    for(int i=1; i<=n; i++)
    {
        cin >> per[i];
    }

    for(int i=1; i<=n; i++)
    {
        sz[i] = a[i], p[i] = i;
    }

    ll mx = 0;
    vector<ll> ans(n);
    vector<bool> vis(n + 1, false);
    for(int i=n-1; i>=0; i--)
    {
        ans[i] = mx;
        vis[per[i + 1]] = 1;
        if (per[i + 1] - 1 > 0 && vis[per[i + 1] - 1])
        {
            Union(per[i + 1], per[i + 1] - 1);
        }

        if (per[i + 1] + 1 <= n && vis[per[i + 1] + 1])
        {
            Union(per[i + 1], per[i + 1] + 1);
        }
        mx = max(mx, get(per[i + 1]));
    }
    for(ll &x : ans) cout << x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
