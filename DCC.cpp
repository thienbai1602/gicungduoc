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
const int mxN = 1e2 + 66;

bool ok[mxN][mxN];
int numRow, numCol, T, a[mxN][mxN];

void ckH()
{
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            int cnt = 0;
            for(int k=r; k<=numRow; k++)
            {
                if (a[k][c] == a[r][c]) ++cnt;
                 else break;
            }

            if (cnt >= T)
            {
                for(int k=r; k<=r+cnt-1; k++)
                {
                    ok[k][c] = true;
                }
            }
        }
    }
}

void ckW()
{
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            int cnt = 0;
            for(int k=c; k<=numCol; k++)
            {
                if (a[r][c] == a[r][k]) ++cnt;
                 else break;
            }

            if (cnt >= T)
            {
                for(int k=c; k<=c+cnt-1; k++)
                {
                    ok[r][k] = true;
                }
            }
        }
    }
}

void solve()
{
    cin >> numRow >> numCol >> T;
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            cin >> a[r][c];
        }
    }

    memset(ok, false, sizeof(ok));
    ckH(), ckW();
    int ans = 0;
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            if (a[r][c] != 0 && !ok[r][c]) ++ans;
        }
    }
    cout << ans;
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
