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

vector<ii> a;
vector<int> adj[mxN];
int n, timer = 0, in[mxN], out[mxN], it[mxN];

void dfs(int u, int p)
{
    in[u] = timer;
    for(int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
    out[u] = timer++;
}

void upd(int id, int x)
{
    for(++id; id<=n; id+=(id & -id))
    {
        it[id] += x;
    }
}

int get(int id)
{
    int ret = 0;
    for(++id; id>0; id-=(id & -id))
    {
        ret += it[id];
    }
    return ret;
}

void solve()
{
    cin >> n;
    a.assign(n, mp(0, 0));
    for(int i=0; i<n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }

    for(int chi=1; chi<n; chi++)
    {
        int p;
        cin >> p;
        --p;
        adj[p].pb(chi);
    }

    dfs(0, -1);
    sort(rall(a));
    vector<int> ans(n, 0);
    for(int i=0; i<n; i++)
    {
        ans[a[i].se] = get(out[a[i].se]) - get(in[a[i].se] - 1);
        upd(out[a[i].se], 1);
    }

    for(int i=0; i<n; i++)
    {
        cout << ans[i] << "\n";
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
