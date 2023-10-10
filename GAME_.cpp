#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 66;

int n;
ll a[mxN], dp[mxN];

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    dp[0] = 0, dp[1] = a[1], dp[2] = a[1] + a[2];
    for(int i=3; i<=n; i++)
    {
        dp[i] = max({dp[i - 1], a[i] + dp[i - 2], a[i] + a[i - 1] + dp[i - 3]});
    }
    cout << dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
