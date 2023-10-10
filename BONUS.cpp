#include    <bits/stdc++.h>
#define ll long long
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

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e3 + 66;

int numRow, numCol, Q;

void solve()
{
    cin >> numRow >> numCol >> Q;
    vector<vector<ll>> a(numRow + 1, vector<ll>(numCol + 1));
    for(int row=1; row<=numRow; row++)
    {
        for(int col=1; col<=numCol; col++)
        {
            cin >> a[row][col];
        }
    }

    vector<vector<ll>> pref(numRow + 1, vector<ll>(numCol + 1));
    for(int row=1; row<=numRow; row++)
    {
        for(int col=1; col<=numCol; col++)
        {
            pref[row][col] = pref[row - 1][col] + pref[row][col - 1] - pref[row - 1][col - 1] + a[row][col];
        }
    }

    while(Q--)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << pref[u][v] - pref[u][y - 1] - pref[x - 1][v] + pref[x - 1][y - 1] << "\n";
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
