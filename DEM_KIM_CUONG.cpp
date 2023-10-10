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
const int mxN = 3e3 + 6;

string S;
int numRow, numCol, add;
int dia[mxN * 2][mxN * 2], pref[mxN * 2][mxN * 2];

bool ck(int R, pair<int, int> &cur)
{
    int u = cur.fi - cur.se + add;
    int v = cur.se + cur.fi;
    int a = 1, b = 1 + (R - 2) * 2;
    if (u + R - 1 > add * 2 || v + R - 1 > add * 2 || u - R + 1 <= 0 || v - R + 1 <= 0) return false;
    int A = (a + b) * ((b - a) / 2 + 1) + (1 + (R - 1) * 2);
    int B = pref[u + R - 1][v + R - 1] - pref[u - R][v + R - 1] - pref[u + R - 1][v - R] + pref[u - R][v - R];
    return (A == B);
}

void solve()
{
    cin >> numRow >> numCol;
    add = max(numRow, numCol) + 1;
    vector<pair<int, int>> store;
    for(int r=1; r<=numRow; r++)
    {
        cin >> S;
        for(int c=1; c<=numCol; c++)
        {
            int u = r - c + add;
            int v = r + c;
            dia[u][v] = (int)(S[c - 1] - '0');
            if (dia[u][v]) store.pb(mp(r, c));
        }
    }

    /*for(int r=1; r<=numRow*2; r++)
    {
        for(int c=1; c<=numCol*2; c++)
        {
            cout << dia[r][c] << (c < numCol * 2 ? " " : "\n");
        }
    }*/

    for(int r=1; r<=add*2; r++)
    {
        for(int c=1; c<=add*2; c++)
        {
            pref[r][c] = pref[r - 1][c] + pref[r][c - 1] + dia[r][c] - pref[r - 1][c - 1];
        }
    }

    int ans = 0;
    for(auto [r, c] : store)
    {
        //int mx = bs(2, min({r, c, numRow - r + 1, numCol - c + 1}), mp(r, c));
        //cout << r << " " << c << " " << mx << "\n";
        pair<int, int> cur = mp(r, c);
        int mx = 1, lo = 2, hi = min({r, c, numRow - r + 1, numCol - c + 1});
        while(lo <= hi)
        {
            int m = (lo + hi) >> 1;
            if (ck(m, cur))
            {
                mx = m;
                lo = m + 1;
            } else
            {
                hi = m - 1;
            }
        }
        ans += mx;
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
