#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int n, m;
int p[mxN], sz[mxN], pos[mxN], x[mxN], y[mxN], w[mxN];

int findp(int u)
{
    if (u != p[u]) return p[u] = findp(p[u]);
     else return u;
}

void Union(int a, int b)
{
    a = findp(a), b = findp(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
}

bool check(ll X)
{
    for(int i=0; i<n; i++)
    {
        sz[i] = 1;
        p[i] = i;
    }

    for(int i=0; i<m; i++)
    {
        if (w[i] >= X)
        {
            Union(x[i], y[i]);
        }
    }

    for(int i=0; i<n; i++)
    {
        if (findp(pos[i]) != findp(i)) return false;
    }
    return true;
}

ll bs(ll l, ll r)
{
    ll ans = 0;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (check(m))
        {
            ans = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> pos[i];
        --pos[i];
    }

    for(int i=0; i<m; i++)
    {
        cin >> x[i] >> y[i] >> w[i];
        --x[i], --y[i];
    }

    bool flat = true;
    for(int i=0; i<n; i++)
    {
        if (pos[i] != i)
        {
            flat = false;
            break;
        }
    }

    if (flat) cout << -1;
     else cout << bs(1, 1e9);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    solve();
    return 0;
}
