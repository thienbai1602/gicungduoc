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
const ll MOD = 1e9;
const int mxN = 1e3 + 66;
const int dx[4] = {1, -1, -2, -2};
const int dy[4] = {-2, -2, -1, 1};

bool ban[mxN][mxN], mark[mxN][mxN];
int numRow, numCol, k, Q;
vector<ii> topo;
ll dp[mxN * mxN];
stack<ii> st;

bool sf(int x, int y)
{
    return (x >= 0 && y >= 0 && x < numRow && y < numCol && !ban[x][y]);
}

void dfs(int x, int y)
{
    mark[x][y] = true;
    for(int dir=0; dir<4; dir++)
    {
        int ux = x + dx[dir], vx = y + dy[dir];
        if (sf(ux, vx) && !mark[ux][vx])
        {
            dfs(ux, vx);
        }
    }
    st.push(mp(x, y));
}

ll cal(ll x, ll y)
{
    return (x * numCol + y);
}

void solve()
{
    cin >> numRow >> numCol >> k >> Q;
    memset(ban, false, sizeof(ban));
    memset(mark, false, sizeof(mark));
    for(int i=0; i<k; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ban[u][v] = true;
    }

    for(int row=0; row<numRow; row++)
    {
        for(int col=0; col<numCol; col++)
        {
            if (ban[row][col] || mark[row][col]) continue;
            dfs(row, col);
        }
    }

    while(!st.empty())
    {
        topo.pb(st.top());
        st.pop();
    }

    memset(dp, 0, sizeof(dp));
    dp[cal(numRow - 1, numCol - 1)] = 1;
    for(int i=0; i<sz(topo); i++)
    {
        ll x = topo[i].fi, y = topo[i].se;
        if (dp[cal(x, y)])
        {
            for(int dir=0; dir<4; dir++)
            {
                int u = x + dx[dir], v = y + dy[dir];
                if (sf(u, v))
                {
                    dp[cal(u, v)] = (dp[cal(u, v)] + dp[cal(x, y)]) % MOD;
                }
            }
        }
    }

    while(Q--)
    {
        int u, v;
        cin >> u >> v;
        cout << dp[cal(--u, --v)] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("SOCACH.INP", "r", stdin);
    //freopen("SOCACH.OUT", "w", stdout);
    solve();
    return 0;
}


