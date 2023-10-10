#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 1e6 + 66;

ll n, m, Q, a, b;
vector<ll> p;

ll dis(ll x, ll y)
{
    return (ll)abs(x - y);
}

void solve()
{
    cin >> n >> m >> Q >> a >> b;
    for(int i=0; i<m; i++)
    {
        ll x;
        cin >> x;
        p.pb(x);
    }

    sort(all(p));
    while(Q--)
    {
        ll u, v, ans;
        cin >> u >> v;
        if (u > v) swap(u, v);
        ans = (v - u) * a;
        auto iter = lower_bound(all(p), u);
        if (iter != p.end())
        {
            int from = iter - p.begin();
            auto it = lower_bound(all(p), v);
            if (it != p.end())
            {
                int to = it - p.begin();
                ans = min(ans, dis(p[from], u) * a + dis(p[to], p[from]) * b + dis(v, p[to]) * a);
            }

            if (it != p.begin())
            {
                int to = it - p.begin() - 1;
                ans = min(ans, dis(p[from], u) * a + dis(p[to], p[from]) * b + dis(v, p[to]) * a);
            }

        }

        if (iter != p.begin())
        {
            int from = iter - p.begin() - 1;
            auto it = lower_bound(all(p), v);
            if (it != p.end())
            {
                int to = it - p.begin();
                ans = min(ans, dis(p[from], u) * a + dis(p[to], p[from]) * b + dis(v, p[to]) * a);
            }

            if (it != p.begin())
            {
                int to = it - p.begin() - 1;
                ans = min(ans, dis(p[from], u) * a + dis(p[to], p[from]) * b + dis(v, p[to]) * a);
            }
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
