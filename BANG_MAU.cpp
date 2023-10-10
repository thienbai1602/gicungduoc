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

int numRow, numCol, k;

void solve()
{
    cin >> numRow >> numCol >> k;
    vector<vector<int>> grid(numRow + 1, vector<int>(numCol + 1, 0));
    for(int i=0; i<k; i++)
    {
        int x, y, u, v, c;
        cin >> x >> y >> u >> v >> c;
        for(; x<=u; x++)
        {
            for(int z=y; z<=v; z++)
            {
                grid[x][z] = c;
            }
        }
    }

    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            cout << grid[r][c] << (c < numCol ? " " : "\n");
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
