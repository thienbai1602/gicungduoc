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

int numRow, numCol, K;
vector<vector<int>> rec;

int S(int x, int y, int u, int v)
{
    return rec[u][v] - rec[u][y - 1] - rec[x - 1][v] + rec[x - 1][y - 1];
}

void solve()
{
    cin >> numRow >> numCol >> K;
    rec.assign(numRow + 1, vector<int>(numCol + 1, 0));
    for(int i=0; i<K; i++)
    {
        int x, y;
        cin >> x >> y;
        rec[x][y] = 1;
    }

    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            rec[r][c] += rec[r - 1][c] + rec[r][c - 1] - rec[r - 1][c - 1];
        }
    }

    ll ans = (K > 0);
    for(int top=1; top<=numRow; top++)
    {
        for(int bottom=top; bottom<=numRow; bottom++)
        {
            int right = 1;
            for(int left=1; left<=numCol; left++)
            {
                right = max(right, left);
                if (S(top, left, bottom, right) > 1) continue;
                while(right < numCol && S(top, left, bottom, right + 1) <= 1)
                {
                    ++right;
                }
                if (S(top, left, bottom, right) == 1) ans = max(ans, 1LL * (bottom - top + 1) * (right - left + 1));
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
