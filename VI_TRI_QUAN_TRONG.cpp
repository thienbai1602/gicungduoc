#include    <bits/stdc++.h>
#define SKY
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

vector<ii> imppos;
ll numRow, numCol, K, f[mxN], g[mxN], b[mxN];

int bs_f(int l, int r, ii &nxt)
{
    int ret = 0;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (imppos[b[m]].se <= nxt.se)
        {
            ret = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ret;
}

int bs_g(int l, int r, ii &nxt)
{
    int ret = 0;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if  (imppos[b[m]].se >= nxt.se)
        {
            ret = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ret;
}

void solve()
{
    cin >> numRow >> numCol >> K;
    for(int i=0; i<K; i++)
    {
        int x, y;
        cin >> x >> y;
        imppos.pb(mp(x, y));
    }
    imppos.pb(mp(1, 1));
    imppos.pb(mp(numRow, numCol));
    sort(all(imppos));

    int res = 1;
    f[1] = b[1] = 1;
    for(int i=2; i<=K+1; i++)
    {
        int pos = bs_f(1, f[res], imppos[i]);
        f[i] = pos + 1;
        if (f[i] > f[res])
        {
            res = i;
            b[f[i]] = i;
        }

        if (imppos[b[pos + 1]].se > imppos[i].se)
        {
            b[pos + 1] = i;
        }
    }

    int mx = f[K + 1];
    res = K + 1; set0(b);
    g[K + 1] = 1, b[1] = K + 1;
    vector<int> cnt(K + 3, 0);
    for(int i=K; i>0; i--)
    {
        int pos = bs_g(1, g[res], imppos[i]);
        g[i] = pos + 1;
        if (g[i] >  g[res])
        {
            res = i;
            b[g[i]] = i;
        }

        if (imppos[b[pos + 1]].se < imppos[i].se)
        {
            b[pos + 1] = i;
        }

        if (f[i] + g[i] - 1 == mx)
        {
            ++cnt[f[i]];
        }
    }

    int ans = 0;
    for(int i=0; i<mx; i++)
    {
        if (cnt[i] == 1) ++ans;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    #endif //SKY
    solve();
    return 0;
}
