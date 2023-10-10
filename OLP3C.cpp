#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
const int mxN = 606;

int n, t, a, b;
ll dp[mxN][mxN], pref[mxN][mxN];

void solve()
{
    cin >> n >> t >> a >> b;
    pref[2][2] = 1;
    for(int step=1; step<=t; step++)
    {
        for(int green=0; green<=n; green++)
        {
            for(int red=0; red<=n-green; red++)
            {
                dp[green + 2][red + 2] =
                  (pref[green + 3][red + 1] * (green + 1) + pref[green + 1][red + 2] * (n - green -  red + 1)) % MOD;
                if (green + red + 1 <= n) dp[green + 2][red + 2] = (dp[green + 2][red + 2] + pref[green + 2][red + 3] * (red + 1)) % MOD;
            }
        }

        for(int green=0; green<=n; green++)
        {
            for(int red=0; red<=n; red++)
            {
                pref[green + 2][red + 2] = dp[green + 2][red + 2];
            }
        }
    }

    /*for(int step=1; step<=t; step++)
    {
        for(int green=0; green<=n; green++)
        {
            for(int red=0; red<=n; red++)
            {
                cout << dp[step][green + 2][red + 2] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }*/

    cout << dp[a + 2][b + 2] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
