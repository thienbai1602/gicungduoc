#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

const ll INF = 1e17;
const int mxN = 1e5 + 66;

int n, K;
ll a[mxN], dif[mxN], tree[mxN * 4];

void build(int id, int l, int r)
{
    if (l == r)
    {
        tree[id] = dif[l];
        return;
    }

    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v)
    {
        return tree[id];
    }

    int m = (l + r) >> 1;
    return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

void solve()
{
    cin >> n >> K;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    for(int i=1; i<n; i++)
    {
        dif[i] = a[i] - a[i - 1];
    }
    build(1, 1, n - 1);

    ll ret = INF, m = n - K;
    for(int i=1; i<=n-m+1; i++)
    {
        ret = min(ret, get(1, 1, n - 1, i, i + m - 2));
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("MAXDIF.INP", "r", stdin);
    freopen("MAXDIF.OUT", "w", stdout);
    solve();
    return 0;
}
