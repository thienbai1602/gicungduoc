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
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int n, Q;
vector<int> a;
vector<vector<int>> seg;

void build(int id, int l, int r)
{
    for(int x=1; x<101; x++)
    {
        seg[id][x] = x;
    }
    if (l == r) return;
    int m = (l + r) >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
}

void down(int id, int l, int r)
{
    for(int x=1; x<101; x++)
    {
        seg[id << 1][x] = seg[id][seg[id << 1][x]];
        seg[id << 1 | 1][x] = seg[id][seg[id << 1 | 1][x]];
    }

    for(int x=1; x<101; x++)
    {
        seg[id][x] = x;
    }
}

void modify(int id, int l, int r, int u, int v, int x, int y)
{
    if (l > v || u > r) return;
    if (u <= l && r <= v)
    {
        for(int val=1; val<101; val++)
        {
            if (seg[id][val] == x)
            {
                seg[id][val] = y;
            }
        }
        return;
    }

    down(id, l, r);
    int m = (l + r) >> 1;
    modify(id << 1, l, m, u, v, x, y);
    modify(id << 1 | 1, m + 1, r, u, v, x, y);
}

void query(int id, int l, int r)
{
    if (l == r)
    {
        cout << seg[id][a[l]] << " ";
        return;
    }

    down(id, l, r);
    int m = (l + r) >> 1;
    query(id << 1, l, m);
    query(id << 1 | 1, m + 1, r);
}

void solve()
{
    cin >> n;
    a.assign(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    seg.assign(4 * n, vector<int>(101, 0));
    build(1, 0, n - 1);

    cin >> Q;
    for(int i=0; i<Q; i++)
    {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        --l, --r;
        modify(1, 0, n - 1, l, r, x, y);
    }
    query(1, 0, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

