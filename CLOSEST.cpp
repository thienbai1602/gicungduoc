#include    <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

const int N = 5e5 + 55;
const ll INF = 1e18;

int n, query;
ll seg[N * 4];

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[l] = INF;
        return;
    }

    int m = (l + r) >> 1;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

void update(int id, int l, int r, int pos, ll val)
{
    if (pos > r || pos < l)
    {
        return;
    }

    if (l == r && r == pos)
    {
        seg[id] = val;
        return;
    }

    int m = (l + r) >> 1;
    update(id * 2, l, m, pos, val);
    update(id * 2 + 1, m + 1, r, pos, val);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

ll get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l)
    {
        return INF;
    }

    if (u <= l && r <= v)
    {
        return seg[id];
    }

    int m = (l + r) >> 1;
    return min(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

void solve()
{
    cin >> n >> query;
    vector<ll> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=1; i<=4 * n; i++)
    {
        seg[i] = INF;
    }

    map<ll, ll> pos;
    vector<vector<pair<int, int>>> listID(n + 1);
    for(int i=0; i<query; i++)
    {
        int l, r;
        cin >> l >> r;
        listID[r].push_back({l, i});
    }

    // cout << "\n";

    vector<ll> ans(query);
    map<ll, ll> closer;
    for(int i=1; i<=n; i++)
    {
        if (closer[a[i - 1]] != 0)
        {
            int pos = closer[a[i - 1]];
            //cout << pos << " " << i << " ";
            update(1, 1, n, pos, i - pos);
            //cout << seg[1] << "\n";
        }

        for(int j=0; j<(int)listID[i].size(); j++)
        {
            pair<int, int> cur = listID[i][j];
            //cout << cur.fi << " " << i << "\n";

            ll tp = get(1, 1, n, cur.fi, i);
            ans[cur.se] = (tp == INF ? -1 : tp);
        }
        closer[a[i - 1]] = i;
    }

    for(int i=0; i<query; i++)
    {
        cout << ans[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
