#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 105;

int n;
ll S = 0, a[mxN], dp[100005];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        S += a[i];
    }

    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++)
    {
        dp[0] = 1;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=S; j>=0; j--)
        {
            if (j >= a[i] && dp[j - a[i]] != -1)
            {
                dp[j] = 1;
            }
        }
    }

    vector<int> res;
    for(int i=1; i<=S; i++)
    {
        if (dp[i] != -1)
        {
            res.push_back(i);
        }
    }

    cout << sz(res) << "\n";
    for(int i=0; i<sz(res); i++)
    {
        cout << res[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
