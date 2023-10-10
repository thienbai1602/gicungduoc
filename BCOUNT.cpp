#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int n, Q, a[mxN], dp[mxN][4];

void solve()
{
    cin >> n >> Q;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    memset(dp, 0, sizeof(dp));
    for(int i=0; i<n; i++)
    {
        for(int type=1; type<=3; type++)
        {
            dp[i + 1][type] = dp[i][type];
        }
        dp[i + 1][a[i]]++;
    }

    for(int i=0; i<Q; i++)
    {
        int u, v;
        cin >> u >> v;
        for(int type=1; type<=3; type++)
        {
            cout << dp[v][type] - dp[u - 1][type] << (type < 3 ? " " : "\n");
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
