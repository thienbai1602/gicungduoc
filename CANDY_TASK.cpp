#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1066;
const ll INF = 1e18;

int n;
ll a[N], S = 0;

void solve()
{
    n = 0;
    while(cin >> a[n])
    {
        ++n;
        S += a[n - 1];
    }

    ll pref = S;  S /= 2;
    vector<ll> dp(S + 1, -1);
    for(int t=1; t<=S; t++)
    {
        dp[t] = INF;
        for(int i=0; i<n; i++)
        {
            if (t >= a[i] && i > dp[t - a[i]])
            {
                dp[t] = i;
                break;
            }
        }
    }

    while(dp[S] > n - 1) --S;

    ll ret = S;
    vector<int> cnt(n + 1, 0);
    while(dp[S] > -1)
    {
        cnt[dp[S]] = 1;
        S -= a[dp[S]];
    }

    cout << pref - ret << " " << ret << "\n";
    for(int i=0; i<n; i++)
    {
        if (!cnt[i]) cout << a[i] << " ";
    }

    cout << "\n";
    for(int i=0; i<n; i++)
    {
        if (cnt[i]) cout << a[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CANDY.INP", "r", stdin);
    //freopen("CANDY.OUT", "w", stdout);
    solve();
    return 0;
}
