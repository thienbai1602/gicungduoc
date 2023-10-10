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
const int mxN = 2e5 + 66;

string S;
int n, desX, desY;

void upd(int &x, int &y, char chr, int d)
{
    if (chr == 'L')
    {
        x -= d;
    }

    if (chr == 'R')
    {
        x += d;
    }

    if (chr == 'U')
    {
        y += d;
    }

    if (chr == 'D')
    {
        y -= d;
    }
}

bool can(int X, int Y, int len)
{
    int d = abs(X - desX) + abs(Y - desY);
    if (d % 2 != len % 2) return false;
    return (len >= d);
}

bool ck(int len)
{
    int x = 0, y = 0;
    for(int i=len; i<n; i++)
    {
        upd(x, y, S[i], 1);
    }


    int l = 0, r = len;
    while(1)
    {
        if (can(x, y, len)) return true;
        if (r == n) break;
        upd(x, y, S[l++], 1);
        upd(x, y, S[r++], -1);
        //if (len == 2) cout << l << " " << r << " " << x << " " << y << "\n";

    }
    return false;
}

void solve()
{
    cin >> n >> S >> desX >> desY;

    if (!ck(n))
    {
        cout << "-1";
        return;
    }

    int l = 0, r = n, ans = -1;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (ck(m))
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
        //cout << m << "\n";
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
