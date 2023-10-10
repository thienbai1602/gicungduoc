#include    <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;

const int mxN = 1066;
const int u[3] = {0, 1, 0};
const int v[3] = {1, 0, -1};

queue<ii> pq;
int N, x, y, gr[mxN][mxN], dis[mxN][mxN];

bool sf(int x, int y)
{
    return (x > 0 && x <= N && y > 0 && y <= N);
}

void solve()
{
    cin >> N >> x >> y;
    memset(dis, 0, sizeof(dis));
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            int x;
            cin >> x;
            dis[i][j] = (x == 1 ? -1 : 0);
        }
    }

    dis[1][1] = 1;
    pq.push(mp(1, 1));
    while(!pq.empty())
    {
        ii nxt = pq.front();
        pq.pop();

        for(int i=0; i<3; i++)
        {
            int ux = nxt.fi + u[i], vx = nxt.se + v[i];
            if (sf(ux, vx) && dis[ux][vx] == 0)
            {
                dis[ux][vx] = dis[nxt.fi][nxt.se] + 1;;
                pq.push(mp(ux, vx));
            }
        }
    }
    cout << (dis[x][y] == -1 || dis[x][y] == 0 ? 0 : dis[x][y]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("RABBIT.INP", "r", stdin);
    freopen("RABBIT.OUT", "w", stdout);
    solve();
    return 0;
}
