#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e3 + 66;

int n;
ll x[mxN], y[mxN], p[mxN], sz[mxN];

ll sq(ll x)
{
    return (ll)x * x;
}

ll dis(int a, int b)
{
    return sq(x[a] - x[b]) + sq(y[a] - y[b]);
}

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
        p[i] = i;
        sz[i] = 1;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if (dis(i, j) <= X)
            {
                Union(i, j);
            }
        }
    }

    int original = findp(0);
    for(int i=1; i<n; i++)
    {
        if (original != findp(i)) return false;
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
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> x[i] >> y[i];
    }
    cout << bs(0, 1e9);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    solve();
    return 0;
}
