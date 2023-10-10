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
const int block = 700;
const ll MOD = 1e9 + 7;
const int mxN = 5e2 + 66;

struct data
{
    ll x, y, u, v, w;
    data(ll x, ll y, ll u, ll v, ll w) : x(x), y(y), u(u), v(v), w(w){
    }
};

vector<data> modify;
int numRow, numCol, Q;
ll a[mxN][mxN], store[mxN][mxN], pref[mxN][mxN];

void rebuild()
{
    set0(store);
    for(auto i : modify)
    {
        store[i.x][i.y] += i.w;
        store[i.x][i.v + 1] += i.w;
        store[i.u + 1][i.y] += i.w;
        store[i.u + 1][i.v + 1] -= i.w;
    }

    modify.clear();
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            store[r][c] += store[r - 1][c] + store[r][c - 1] - store[r - 1][c - 1];
            a[r][c] += store[r][c];
            pref[r][c] = pref[r - 1][c] + pref[r][c - 1] + a[r][c] - pref[r - 1][c - 1];
        }
    }
}

void solve()
{
    cin >> numRow >> numCol >> Q;
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            cin >> a[r][c];
        }
    }

    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            pref[r][c] = pref[r - 1][c] + pref[r][c - 1] + a[r][c] - pref[r - 1][c - 1];
        }
    }

    while(Q--)
    {
        if (Q % block == 0)
        {
            rebuild();
        }

        int tc;
        cin >> tc;
        if (tc == 1)
        {
            ll x, y, u, v, w;
            cin >> x >> y >> u >> v >> w;
            modify.pb(data(x, y, u, v, w));
        } else
        {
            ll x, y, u, v;
            cin >> x >> y >> u >> v;
            ll ans = pref[u][v] - pref[u][y - 1] - pref[x - 1][v] + pref[x - 1][y - 1];
            for(auto i : modify)
            {
                i.x = max(x, i.x);
                i.y = max(y, i.y);
                i.u = min(u, i.u);
                i.v = min(v, i.v);

                if (i.x > i.u || i.y > i.v) continue;
                ans += (i.u - i.x + 1) * (i.v - i.y + 1) * i.w;
            }
            cout << ans << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    solve();
    return 0;
}
