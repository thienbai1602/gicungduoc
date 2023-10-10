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
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 2e5 + 66;

int n, Q;
ll mx[LOG][mxN], h[mxN], lg[mxN];

int get(int l, int r)
{
    int k = lg[r - l + 1];
    return max(mx[k][l], mx[k][r - (1 << k) + 1]);
}

int bsL(int l, int r, int X)
{
    int ret = -1, st = l;
    while(l <= r)
    {
        int m = (l + r) >> 1, nxt = get(st, m);
        if (nxt >= X)
        {
            ret = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }
    return ret;
}

void solve()
{
    cin >> n >> Q;
    for(int i=1; i<=n; i++)
    {
        cin >> h[i];
        mx[0][i] = h[i];
    }

    lg[1] = 0;
    for(int i=2; i<=n; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }

    for(int k=1; k<LOG; k++)
    {
        for(int i=1; i+(1 << k)-1<=n; i++)
        {
            mx[k][i] = max(mx[k - 1][i], mx[k - 1][i + (1 << (k - 1))]);
        }
    }
    while(Q--)
    {
        ll L, R, ans = 0;
        cin >> L >> R;
        int cur = 0, pos = 1;
        while(pos <= n)
        {
            int nxtPos = bsL(pos, n, L);
            if (nxtPos == -1) break;
            pos = nxtPos + 1;
            if (h[nxtPos] > R) continue;
            //nxtPos = bsR(nxtPos, n, R);
            //cout << nxtPos << "\n";
            //cout << cur << " " << nxtPos << "\n";
            if (cur != 0) ans += abs(h[cur] - h[nxtPos]);
            cur = nxtPos;
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
