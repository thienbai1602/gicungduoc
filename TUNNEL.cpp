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
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

bool vis[mxN][mxN];
int tc, numRow, numCol, garden[mxN][mxN];

bool sf(int x, int y)
{
    return (x > 0 && y > 0 && x <= numRow && y <= numCol && !vis[x][y] && garden[x][y]);
}

int bfs(int x, int y)
{
    queue<ii> pq;
    pq.push(mp(x, y)); vis[x][y] = true;

    int ret = 0;
    while(!pq.empty())
    {
        int u = pq.front().fi, v = pq.front().se;
        pq.pop(); ++ret;

        for(int dir=0; dir<4; dir++)
        {
            int ux = u + dx[dir], vx = v + dy[dir];
            if (sf(ux, vx))
            {
                vis[ux][vx] = true;
                pq.push(mp(ux, vx));
            }
        }
    }
    return ret;
}

void solve()
{
    cin >> numRow >> numCol;
    set0(garden);
    for(int i=1; i<=numRow; i++)
    {
        string S;
        cin >> S;
        for(int j=1; j<=numCol; j++)
        {
            garden[i][j] = (S[j - 1] - '0');
        }
    }

    int ans = 0;
    memset(vis, false, sizeof(vis));
    for(int row=1; row<=numRow; row++)
    {
        for(int col=1; col<=numCol; col++)
        {
            if (!vis[row][col] && garden[row][col])
            {
                ans = max(ans, bfs(row, col));
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("TUNNEL.INP", "r", stdin);
    freopen("TUNNEL.OUT", "w", stdout);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
