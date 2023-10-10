#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e18;
const int mxN = 1e6 + 66;

int n, K;
ll h[mxN], dp[mxN];

void solve()
{
    cin >> n >> K;
    for(int i=1; i<=n; i++)
    {
        cin >> h[i];
    }

    memset(dp, 0, sizeof(dp));
    for(int i=2; i<=n; i++)
    {
        dp[i] = INF;
        for(int j=max(1, i-K); j<i; j++)
        {
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
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
