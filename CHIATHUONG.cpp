#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 166;

int n, a[mxN], S = 0;
int dp[600005][mxN / 2], pref[60005][mxN / 2];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        S += a[i];
    }

    memset(dp, -1, sizeof(dp));
    memset(pref, -1, sizeof(pref));

    pref[0][0] = dp[0][0] = 1;
    for(int i=0; i<n; i++)
    {
        for(int j=S; j>=0; j--)
        {
            for(int per=0; per<=min(i, n/2); per++)
            {
                if (j >= a[i] && pref[j - a[i]][per] != -1)
                {
                    dp[j][per + 1] = 1;
                }
            }
        }

        for(int j=S; j>=0; j--)
        {
            for(int per=0; per<=min(i + 1, n/2 + 1); per++)
            {
                pref[j][per] = dp[j][per];
            }
        }
    }

    ll dis = 1e15, a, b;
    for(int j=S/2; j>=0; j--)
    {
        for(int per=n/2; per<=n/2 + (n % 2) ; per++)
        {
            if (dp[j][per] != -1)
            {
                if (dis > abs(S - 2 * j))
                {
                    dis = abs(S - 2 * j);
                    a = min(j, S - j), b = max(j, S - j);
                }
            }
        }
    }
    cout << a << " " << b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CHIATHUONG.INP", "r", stdin);
    freopen("CHIATHUONG.OUT", "w", stdout);
    solve();
    return 0;
}
