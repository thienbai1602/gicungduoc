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

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int n, Q, lg[mxN];
map<ll, int> pos;
ll a[mxN], mi[LOG][mxN], mx[LOG][mxN], g[LOG][mxN];

ll getMin(int l, int r)
{
    int k = lg[r - l + 1];
    return min(mi[k][l], mi[k][r - (1 << k) + 1]);
}

ll getMax(int l, int r)
{
    int k = lg[r - l + 1];
    return max(mx[k][l], mx[k][r - (1 << k) + 1]);
}

ll getGcd(int l, int r)
{
    int k = lg[r - l + 1];
    return __gcd(g[k][l], g[k][r - (1 << k) + 1]);
}

void solve()
{
    cin >> n >> Q;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        mi[0][i] = mx[0][i] = a[i];
        g[0][i] = a[i] - a[i - 1];
    }

    lg[1] = 0;
    for(int i=2; i<=n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    for(int k=1; k<LOG; k++)
    {
        for(int i=1; i+(1<<k)-1<=n; i++)
        {
            mi[k][i] = min(mi[k - 1][i], mi[k - 1][i + (1 << (k - 1))]);
            mx[k][i] = max(mx[k - 1][i], mx[k - 1][i + (1 << (k - 1))]);
            g[k][i] = __gcd(g[k - 1][i], g[k - 1][i + (1 << (k - 1))]);
        }
    }

    vector<vector<ii>> r(n + 1, vector<ii>());
    for(int i=0; i<Q; i++)
    {
        int u, v;
        cin >> u >> v;
        r[v].pb(mp(u, i));
    }

    int u = 1;
    vector<bool> ans(Q);
    for(int v=1; v<=n; v++)
    {
        if (pos[a[v]]) u = max(u, pos[a[v]] + 1);
        for(auto it : r[v])
        {
            if (it.fi == v || it.fi < u) ans[it.se] = false;
             else
             {
                 ll st = getMin(it.fi, v), ed = getMax(it.fi, v);
                 ll gd = abs(getGcd(it.fi + 1, v));
                 if ((ed - st) % (v - it.fi) != 0)
                 {
                     ans[it.se] = false;
                     continue;
                 }

                 ll x = (ed - st) / (v - it.fi);
                 ans[it.se] = (x == gd);
             }
        }
        pos[a[v]] = v;
    }

    for(int i=0; i<Q; i++)
    {
        cout << (ans[i] ? "YES" : "NO") << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
