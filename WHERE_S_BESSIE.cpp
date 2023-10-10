#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 25;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

struct recta
{
    int x, y, u, v;
    recta(int _x = 0, int _y = 0, int _u = 0, int _v = 0)
    {
        x = _x, y = _y, u = _u, v = _v;
    }

    bool is_inside(recta other)
    {
        return (x >= other.x && u <= other.u && y >= other.y && v <= other.v);
    }
};

int N;
char rec[mxN][mxN];
bool vis[mxN][mxN];
vector<recta> ans;

bool sf(int x, int y, int row_left, int col_left, int row_right, int col_right)
{
    return (x >= row_left && x <= row_right && y >= col_left && y <= col_right && !vis[x][y]);
}

void bfs(int stx, int sty, int row_left, int col_left, int row_right, int col_right)
{
    queue<ii> pq; pq.push(mp(stx, sty));
    char bg = rec[stx][sty];
    vis[stx][sty] = true;

    while(!pq.empty())
    {
        int u = pq.front().fi, v = pq.front().se;
        pq.pop();

        for(int dir=0; dir<4; dir++)
        {
            int x = u + dx[dir], y = v + dy[dir];
            if (sf(x, y, row_left, col_left, row_right, col_right) && rec[x][y] == bg)
            {
                pq.push(mp(x, y));
                vis[x][y] = true;
            }
        }
    }
}

int sl(char c, int row_left, int col_left, int row_right, int col_right)
{
    int ans = 0;
    for(int row=row_left; row<=row_right; row++)
    {
        for(int col=col_left; col<=col_right; col++)
        {
            if (!vis[row][col] && rec[row][col] == c)
            {
                ++ans;
                bfs(row, col, row_left, col_left, row_right, col_right);
            }
        }
    }
    return ans;
}

bool check(int x, int y, int u, int v)
{
    int cnt = 0, sz_1 = 0, sz_char = 0;
    memset(vis, false, sizeof(vis));
    for(char c='A'; c<='Z'; c++)
    {
        int ct = sl(c, x, y, u, v);
        if (ct == 1) ++sz_1;
        sz_char += (ct > 0);
        cnt += ct;
    }
    return (cnt > 2 && sz_1 == 1 && sz_char == 2);
}

void solve()
{
    cin >> N;
    for(int row=1; row<=N; row++)
    {
        for(int col=1; col<=N; col++)
        {
            cin >> rec[row][col];
        }
    }

    for(int row_left=1; row_left<=N; row_left++)
    {
        for(int col_left=1; col_left<=N; col_left++)
        {
            for(int row_right=row_left; row_right<=N; row_right++)
            {
                for(int col_right=col_left; col_right<=N; col_right++)
                {
                    if (check(row_left, col_left, row_right, col_right))
                    {
                        ans.pb(recta(row_left, col_left, row_right, col_right));
                    }
                }
            }
        }
    }

    int ret = 0;
    for(int i=0; i<sz(ans); i++)
    {
        bool valid = true;
        for(int j=0; j<sz(ans); j++)
        {
            if (i == j) continue;
            if (ans[i].is_inside(ans[j]))
            {
                valid = false;
                break;
            }
        }
        ret += valid;
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    solve();
    return 0;
}


