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
const int mxN = 300 + 66;
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

struct St
{
    ll w, xRow, yCol;
    St(ll _w = 0, ll _xRow = 0, ll _yCol = 0)
    {
        w = _w, xRow = _xRow, yCol = _yCol;
    }
};

int N, Q, matrix[mxN][mxN];
bool vis[mxN][mxN];
vector<St> seg;

bool sf(int x, int y)
{
    return (x >= 0 && y >= 0 && x < N && y < N);
}

void bfs(int x, int y, int w)
{
    queue<St> pq; pq.push(St(w, x, y));
    memset(vis, false, sizeof(vis));
    vis[x][y] = true;

    while(!pq.empty())
    {
        St nxt = pq.front(); pq.pop();
        int u = nxt.xRow, v = nxt.yCol, val = nxt.w;

        for(int dir=0; dir<8; dir++)
        {
            int ux = u + dx[dir], vx = v + dy[dir];
            if (sf(ux, vx) && val > 1 && !vis[ux][vx])
            {
                matrix[ux][vx] += (val - 1);
                pq.push(St(val - 1, ux, vx));
                vis[ux][vx] = true;
            }
        }
    }
}

void solve()
{
    cin >> N >> Q;
    for(int i=0; i<Q; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        seg.pb(St(w, u, v));
    }

    for(auto [w, u, v] : seg)
    {
        matrix[u][v] += w;
        bfs(u, v, w);
    }

    int ans = 0;
    for(int row=0; row<N; row++)
    {
        for(int col=0; col<N; col++)
        {
            ans = max(ans, matrix[row][col]);
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
