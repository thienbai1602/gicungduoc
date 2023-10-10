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
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const int mxM = 3e4;
const int mxN = 6e4 + 66;

int tc, numRow, numCol, K, seg[mxN * 4];

void upd(int id, int l, int r, int k, int x)
{
    if (l > k || k > r) return;
    if (l == r && k == l)
    {
        seg[id] = min(seg[id], x);
        return;
    }

    int m = (l + r) >> 1;
    upd(id * 2, l, m, k, x);
    upd(id * 2 + 1, m + 1, r, k, x);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v)
{
    if (u > r || l > v) return INF;
    if (u <= l && r <= v) return seg[id];
    int m = (l + r) >> 1;
    return min(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

void solve()
{
    cin >> numRow >> numCol >> K;
    vector<vector<int>> table(min(numRow, numCol) + 1, vector<int>(max(numRow, numCol) + 1));
    if (numRow > numCol)
    {
        for(int r=1; r<=numRow; r++)
        {
            for(int c=1; c<=numCol; c++)
            {
                char chr;
                cin >> chr;
                table[c][r] = (chr == 'A' ? 1 : -1);
            }
        }
        swap(numRow, numCol);
    } else
    {
        for(int r=1; r<=numRow; r++)
        {
            for(int c=1; c<=numCol; c++)
            {
                char chr;
                cin >> chr;
                table[r][c] = (chr == 'A' ? 1 : -1);
            }
        }
    }

    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            table[r][c] += table[r - 1][c] + table[r][c - 1] - table[r - 1][c - 1];
        }
    }

    int ans = 0;
    for(int r1=1; r1<=numRow; r1++)
    {
        for(int r2=r1; r2<=numRow; r2++)
        {
            if ((r2 - r1 + 1) * numCol <= ans) continue;
            fill(seg, seg + mxN * 4, INF);
            upd(1, 1, mxN, mxM, 0);
            for(int c2=1; c2<=numCol; c2++)
            {
                int c1 = INF, S = table[r2][c2] - table[r1 - 1][c2] - table[r2][0] + table[r1][0];
                if ((r2 - r1 + 1) * c2 > ans) c1 = get(1, 1, mxN, S - K + mxM, S + K + mxM);
                upd(1, 1, mxN, S + mxM, c2);
                if (c1 == INF) continue;
                ans = max(ans, (r2 - r1 + 1) * (c2 - c1));
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
