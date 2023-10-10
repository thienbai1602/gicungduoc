#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 3e3 + 66;

int n;
ll p[mxN], f[mxN], g[mxN];

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> p[i];
    }

    f[1] = 1;
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            if (p[j] <= p[i])
            {
                ++f[i];
            }
        }
    }

    g[n] = 1;
    for(int i=n-1; i>0; i--)
    {
        for(int j=i; j<=n; j++)
        {
            if (p[j] >= p[i])
            {
                ++g[i];
            }
        }
    }

    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            ll x = max({(ll)abs(p[i] - p[j]), (ll)j - f[i], (ll)(n - g[j] + 1) - i});
            ans += x;
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
