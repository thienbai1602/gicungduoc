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

int numRow, numCol;
vector<vector<int>> pref;

int S(int x, int y, int u, int v)
{
    return pref[u][v] - pref[x - 1][v] - pref[u][y - 1] + pref[x - 1][y - 1];
}

void solve()
{
    cin >> numRow >> numCol;
    vector<vector<int>> a(numRow + 1, vector<int>(numCol + 1));
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            cin >> a[r][c];
        }
    }

    pref.assign(numRow + 1, vector<int>(numCol + 1, 0));
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            pref[r][c] = pref[r - 1][c] + pref[r][c - 1] - pref[r - 1][c - 1] + a[r][c];
        }
    }

    int ans = 0;
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            if (a[r][c] != 9) continue;
            int right = c, bottom = r;
            while(right < numCol && a[r][right + 1] == 9) ++right;
            while(bottom < numRow && a[bottom + 1][c] == 9) ++bottom;
            while(c <= right)
            {
                int tp = bottom;
                while(r <= tp && S(r, c, tp, right) != 9 * (tp - r + 1) * (right - c + 1)) --tp;

                if (S(r, c, tp, right) == 9 * (tp - r + 1) * (right - c  + 1))
                {
                    ans = max((tp - r + 1) * (right - c + 1), ans);
                }
                --right;
            }

        }
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
