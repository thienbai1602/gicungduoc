#include    <bits/stdc++.h>
//#define SKY
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
const int mxN = 5e3 + 66;

int N, T, Q;
vector<vector<int>> row, col;

void upd(vector<vector<int>> &a, int rc, int x, int y)
{
    a[rc][x]++, a[rc][y + 2]++;
    a[rc][x + (y - x + 1) / 2 + 1]--;
    a[rc][x + (y - x + 1) / 2 + (y - x + 1) % 2]--;
}

void rebuild(vector<vector<int>> &a)
{
    for(int r=1; r<=N; r++)
    {
        for(int c=1; c<=N; c++)
        {
            a[r][c] += a[r][c - 1];
        }
    }

    for(int r=1; r<=N; r++)
    {
        for(int c=1; c<=N; c++)
        {
            a[r][c] += a[r][c - 1];
        }
    }
}

void solve()
{
    cin >> N >> T;
    row.assign(N + 5, vector<int>(N + 5, 0));
    col.assign(N + 5, vector<int>(N + 5, 0));
    for(int i=0; i<T; i++)
    {
        int tc, rc, x, y;
        cin >> tc >> rc >> x >> y;
        if (tc == 1)
        {
            upd(row, rc, x, y);
        } else
        {
            upd(col, rc, x, y);
        }
    }

    rebuild(row); rebuild(col);

    cin >> Q;
    while(Q--)
    {
        int x, y;
        cin >> x >> y;
        cout << row[x][y] + col[y][x] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif //SKY
    solve();
    return 0;
}
