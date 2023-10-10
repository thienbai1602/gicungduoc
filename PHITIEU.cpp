#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e6 + 55;

int n;
ll a[mxN], dp[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    dp[1] = a[0], dp[2] = a[0] + a[1];
    for(int i=3; i<=n; i++)
    {
        dp[i] = max({dp[i - 1], a[i - 1] + dp[i - 2], a[i - 1] + a[i - 2] + dp[i - 3]});
    }

    ll ps = n;
    vector<ll> res;
    while(ps > 0)
    {
        if (dp[ps] == dp[ps - 1])
        {
            ps--;
            continue;
        }

        if (dp[ps] == a[ps - 1] + dp[ps - 2])
        {
            res.push_back(ps);
            ps -= 2;
        } else
        {
            res.push_back(ps);
            res.push_back(ps - 1);
            ps -= 3;
        }
    }

    cout << sz(res) << " " << dp[n] << "\n";
    for(int i=0; i<sz(res); i++)
    {
        cout << res[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("PHITIEU.INP", "r", stdin);
    freopen("PHITIEU.OUT", "w", stdout);
    solve();
    return 0;
}
