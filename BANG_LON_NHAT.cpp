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
const int mxN = 2e3 + 66;

int numRow, numCol;
ll X, a[mxN], b[mxN];

void solve()
{
    cin >> numRow >> numCol;
    for(int i=1; i<=numRow; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for(int i=1; i<=numCol; i++)
    {
        cin >> b[i];
        b[i] += b[i - 1];
    }
    cin >> X;

    vector<ll> row(numRow + 1, INF);
    for(int top=1; top<=numRow; top++)
    {
        for(int bottom=top; bottom<=numRow; bottom++)
        {
            row[bottom - top + 1] = min(row[bottom - top + 1], a[bottom] - a[top - 1]);
        }
    }

    vector<ll> col(numCol + 1, INF);
    for(int left=1; left<=numCol; left++)
    {
        for(int right=left; right<=numCol; right++)
        {
            col[right - left + 1] = min(col[right - left + 1], b[right] - b[left - 1]);
        }
    }

    int ans = 0;
    for(int i=1; i<=numRow; i++)
    {
        for(int j=1; j<=numCol; j++)
        {
            if (row[i] * col[j] <= X)
            {
                ans = max(ans, i * j);
            }
        }
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

