#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 5e5 + 66;
const ll MOD = 1e9 + 7;

int tc, n;
ll a[mxN], cnt[70];

void solve()
{
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        for(int mask=0; mask<60; mask++)
        {
            if (a[i] & (1LL << mask))
            {
                ++cnt[mask];
            }
        }
    }

    ll ret = 0;
    for(int j=0; j<n; j++)
    {
        ll avs = 0, ovs = 0;
        for(int mask=0; mask<60; mask++)
        {
            ll tp = (1LL << mask) % MOD;
            if (a[j] & (1LL << mask))
            {
                avs = (avs + tp * cnt[mask]) % MOD;
                ovs = (ovs + tp * n) % MOD;
            } else
            {
                avs %= MOD;
                ovs = (ovs + tp * cnt[mask]) % MOD;
            }
        }
        ret = (ret + avs * ovs) % MOD;
    }
    cout << ret << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
