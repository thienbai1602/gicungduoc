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
const int mxN = 5e2 + 66;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int N, M;
vector<ii> hole;
bool vis[mxN][mxN];
ll grid[mxN][mxN], f[mxN][mxN];

bool sf(int x, int y)
{
    return (x > 0 && x <= N && y > 0 && y <= M);
}

bool check(ll D)
{
    int cur = 0;
    queue<ii> pq;
    pq.push(hole[0]);
    memset(vis, false, sizeof(vis));
    vis[hole[0].fi][hole[0].se] = true;

    while(!pq.empty())
    {
        int u = pq.front().fi, v = pq.front().se;
        cur += f[u][v];
        pq.pop();

        for(int dir=0; dir<4; dir++)
        {
            int x = u + dx[dir], y = v + dy[dir];
            if (sf(x, y) && abs(grid[x][y] - grid[u][v]) <= D && !vis[x][y])
            {
                pq.push(mp(x, y));
                vis[x][y] = true;
            }
        }
    }
    return cur == sz(hole);
}

ll bs(ll l, ll r)
{
    ll ans = -1;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (check(m))
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> N >> M;
    for(int row=1; row<=N; row++)
    {
        for(int col=1; col<=M; col++)
        {
            cin >> grid[row][col];
        }
    }

    for(int row=1; row<=N; row++)
    {
        for(int col=1; col<=M; col++)
        {
            cin >> f[row][col];
            if (f[row][col]) hole.pb(mp(row, col));
        }
    }
    cout << (hole.empty() ? 0 : bs(0, 1e9));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
