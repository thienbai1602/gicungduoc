#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e3 + 66;

int n, M;
int w[mxN], v[mxN], a[mxN];

void solve()
{
    cin >> n >> M;
    for(int i=0; i<n; i++)
    {
        cin >> w[i] >> v[i] >> a[i];
    }

    vector<ii> things;
    for(int i=0; i<n; i++)
    {
        int base_2 = 1;
        while(base_2 <= a[i])
        {
            things.pb(mp(base_2 * w[i], base_2 * v[i]));
            a[i] -= base_2;
            base_2 *= 2;
        }

        if (a[i] > 0)
        {
            things.pb(mp(a[i] * w[i], a[i] * v[i]));
        }
    }

    vector<ll> dp(M + 1, -1);
    dp[0] = 0;
    for(int i=0; i<sz(things); i++)
    {
        for(int j=M; j>=0; j--)
        {
            if (j - things[i].fi >= 0 && dp[j - things[i].fi] != -1)
            {
                dp[j] = max(dp[j - things[i].fi] + things[i].se, dp[j]);
            }
        }
    }

    ll ans = 0;
    for(int j=M; j>=0; j--)
    {
        ans = max(ans, dp[j]);
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
