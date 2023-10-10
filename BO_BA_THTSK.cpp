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

ll cnt[3][mxN];
int tc, numRow, numCol;

void solve()
{
    cin >> numRow >> numCol;
    vector<vector<int>> C(numRow + 1, vector<int>(numCol + 1, 0));
    for(int r=1; r<=numRow; r++)
    {
        string S;
        cin >> S;
        for(int c=1; c<=numCol; c++)
        {
            C[r][c] = (int)(S[c - 1] - '0');
        }
    }

    set0(cnt);
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            if (C[r][c] != 0) ++cnt[C[r][c]][c];
        }
    }

    /*for(int c=1; c<=numCol; c++)
    {
        for(int col=1; col<3; col++)
        {
            cout << cnt[col][c] << (col < 2 ? " " : "\n");
        }
    }
    cout << "\n";*/

    ll ans = 0;
    for(int r=1; r<=numRow; r++)
    {
        vector<ll> ct(3, 0);
        for(int c=1; c<=numCol; c++)
        {
            if (C[r][c] != 0) ++ct[C[r][c]];
        }

        /*for(int col=0; col<3; col++)
        {
            cout << ct[col] << (col < 2 ? " " : "\n");
        }*/

        for(int c=1; c<=numCol; c++)
        {
            for(int col=1; col<3; col++)
            {
                if (col == C[r][c] || C[r][c] == 0) continue;
                ans += ct[col] * cnt[col][c];
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
