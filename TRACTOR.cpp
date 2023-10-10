#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 566;
const int u[4] = {0, 1, 0, -1};
const int v[4] = {1, 0, -1, 0};

int N;
ll field[mxN][mxN], p[mxN * mxN], component[mxN * mxN];

struct Ceil
{
    ll x, y;
    Ceil(ll _x = 0, ll _y = 0)
    {
        x = _x, y = _y;
    }
};

struct edge
{
    Ceil from, to;
    ll cost;

    edge(Ceil _from, Ceil _to, ll _cost)
    {
        from = _from, to = _to, cost = _cost;
    }

    bool operator < (edge a)
    {
        return cost < a.cost;
    }
};

bool sf(int u, int v)
{
    return (u >= 0 && u < N && v >= 0 && v < N);
}

int findp(int u)
{
    if (u == p[u]) return u;
    return p[u] = findp(p[u]);
}

bool Union(int a, int b)
{
    a = findp(a), b = findp(b);
    if (a == b) return false;
    if (component[a] < component[b]) swap(a, b);
    component[a] += component[b];
    p[b] = a;
    return component[a] * 2 >= N * N;
}

void solve()
{
    cin >> N;
    for(int row=0; row<N; row++)
    {
        for(int col=0; col<N; col++)
        {
            cin >> field[row][col];
        }
    }

    vector<edge> adj;
    for(int row=0; row<N; row++)
    {
        for(int col=0; col<N; col++)
        {
            for(int i=0; i<4; i++)
            {
                int newRow= row + u[i], newCol = col + v[i];
                if (sf(newRow, newCol) && field[row][col] >= field[newRow][newCol])
                {
                    adj.pb(edge(Ceil(row, col), Ceil(newRow, newCol), field[row][col] - field[newRow][newCol]));
                }
            }
        }
    }

    sort(all(adj));

    for(int row=0; row<N; row++)
    {
        for(int col=0; col<N; col++)
        {
            component[row * N + col] = 1;
            p[row * N + col] = row * N + col;
        }
    }

    for(edge& edges : adj)
    {
        if (Union(edges.from.x * N + edges.from.y, edges.to.x * N + edges.to.y))
        {
            cout << edges.cost;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("tractor.in", "r", stdin);
    freopen("tractor.out", "w", stdout);
    solve();
    return 0;
}
