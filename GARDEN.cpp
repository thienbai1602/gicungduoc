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
const int mxN = 1e3 + 66;

ll h[mxN][mxN];
int numRow, numCol;

bool ck(ll X)
{
    vector<vector<int>> a(numRow + 1, vector<int>(numCol + 1, 0));
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            if (h[r][c] >= X) a[r][c] = 1;
        }
    }

    set<ii> store;
    for(int r=1; r<=numRow; r++)
    {
        for(int x=1; x<=numCol; x++)
        {
            if (a[r][x] == 1)
            {
                for(int y=x+1; y<=numCol; y++)
                {
                    if (a[r][y] == 1)
                    {
                        if (store.find(mp(x, y)) != store.end()) return true;
                        store.insert(mp(x, y));
                    }
                }
            }
        }
    }
    return false;
}

void solve()
{
    cin >> numRow >> numCol;
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            cin >> h[r][c];
        }
    }

    ll l = 0, r = 1e9, ans = -1;
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
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
