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
const int mxN = 1e6 + 66;

vector<vector<ll>> p;
int tc, numRow, numCol;

bool check(ll X)
{
    vector<bool> was_bought(numCol, false);
    bool flat = false;
    for(int r=0; r<numRow; r++)
    {
        int cnt = 0;
        for(int c=0; c<numCol; c++)
        {
            if (p[r][c] >= X)
            {
                ++cnt;
                was_bought[c] = true;
            }
        }
        if (cnt > 1) flat = true;
    }

    if (!flat) return false;
    bool ans = true;
    for(bool b : was_bought)
    {
        ans &= b;
    }
    return ans;
}

void solve()
{
    cin >> numRow >> numCol;
    p.assign(numRow, vector<ll>(numCol));
    for(int r=0; r<numRow; r++)
    {
        for(int c=0; c<numCol; c++)
        {
            cin >> p[r][c];
        }
    }

    ll l = 1, r = (ll)1e9, ans = 0;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (check(m))
        {
            ans = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
