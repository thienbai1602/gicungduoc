#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 5e4 + 66;
const ll INF = 1e18;

struct State
{
    ll left, right, ans, sum;

    State(ll _left = 0, ll _right = 0, ll _ans = 0, ll _sum = 0)
    {
        left = _left, right = _right, ans = _ans, sum = _sum;
    }
}tree[mxN * 4];

int n, Q;
ll a[mxN];

State combine(State x, State y)
{
    ll le = max(x.left, x.sum + y.left);
    ll ri = max(y.right, y.sum + x.right);
    ll S = x.sum + y.sum;
    ll as = max({x.ans, y.ans, x.right + y.left});
    return State(le, ri, as, S);
}

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = State(a[l], a[l], a[l], a[l]);
        return;
    }

    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
}

void upd(int id, int l, int r, int x, ll y)
{
    if (l > x || x > r) return;
    if (l == r && r == x)
    {
        tree[id] = State(y, y, y, y);
        return;
    }

    int m = (l + r) >> 1;
    upd(id * 2, l, m, x, y);
    upd(id * 2 + 1, m + 1, r, x, y);
    tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
}

State get(int id, int l, int r, int x, ll y)
{
    if (x > y || l > r || x > r || y < l) return State(-INF, -INF, -INF, 0);
    if (x <= l && r <= y)
    {
        return tree[id];
    }

    int m = (l + r) >> 1;
    return combine(get(id * 2, l, m, x, y), get(id * 2 + 1, m + 1, r, x, y));
}

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);

    cin >> Q;
    while(Q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            ll x, y;
            cin >> x >> y;
            upd(1, 1, n, x, y);
        } else
        {
            ll x, y;
            cin >> x >> y;
            cout << get(1, 1, n, x, y).ans << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
