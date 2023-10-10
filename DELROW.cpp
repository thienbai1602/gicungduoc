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

int numRow, numCol;
string col[mxN];

void solve()
{
    cin >> numRow >> numCol;
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            char chr;
            cin >> chr;
            col[c] = chr + col[c];
        }
    }

    sort(col + 1, col + 1 + numCol);
    int ans = 0;
    for(int id=1; id<numCol; id++)
    {
        for(int j=0; j<numRow; j++)
        {
            if (col[id][j] != col[id + 1][j])
            {
                ans = max(ans, j);
                break;
            }
        }
    }
    cout << numRow - ans - 1;
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
