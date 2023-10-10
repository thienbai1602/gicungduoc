#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 566;

struct edge
{
    ll u, v, w;
    edge(ll _u = 0, ll _v = 0, ll _w = 0)
    {
        u = _u, v = _v, w = _w;
    }

    bool operator < (edge x)
    {
        return w < x.w;
    }
};

int numRow, numCol;
bool is_starting[mxN][mxN];
ll grid[mxN][mxN], p[mxN * mxN], sz[mxN * mxN], process_node[mxN * mxN], T;

ll to_int(ll x, ll y)
{
    return x * numCol + y;
}

ll findp(int u)
{
    if (u == p[u]) return u;
    return p[u] = findp(p[u]);
}

void Union(int a, int b)
{
    a = findp(a), b = findp(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
    process_node[a] += process_node[b];
}

void solve()
{
    cin >> numRow >> numCol >> T;
    memset(is_starting, false, sizeof(is_starting));
    for(int row=0; row<numRow; row++)
    {
        for(int col=0; col<numCol; col++)
        {
            cin >> grid[row][col];
        }
    }

    for(int row=0; row<numRow; row++)
    {
        for(int col=0; col<numCol; col++)
        {
            cin >> is_starting[row][col];
        }
    }

    for(int row=0; row<numRow; row++)
    {
        for(int col=0; col<numCol; col++)
        {
            ll x = to_int(row, col);
            sz[x] = 1;
            p[x] = x;
            process_node[x] = is_starting[row][col];
        }
    }

    vector<edge> adj;
    for(int row=0; row<numRow; row++)
    {
        for(int col=0; col<numCol; col++)
        {
            if (row < numRow - 1)
            {
                adj.pb(edge(to_int(row, col), to_int(row + 1, col), (ll)abs(grid[row][col] - grid[row + 1][col])));
            }

            if (col < numCol - 1)
            {
                adj.pb(edge(to_int(row, col), to_int(row, col + 1), (ll)abs(grid[row][col] - grid[row][col + 1])));
            }
        }
    }

    sort(all(adj));

    ll ans = 0;
    for(edge &e : adj)
    {
        Union(e.u, e.v);
        ll par = findp(e.u);
        if (sz[par] >= T)
        {
            ans += e.w * process_node[par];
            process_node[par] = 0;
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("skilevel.in", "r", stdin);
    freopen("skilevel.out", "w", stdout);
    solve();
    return 0;
}
