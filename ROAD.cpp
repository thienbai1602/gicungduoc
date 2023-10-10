#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll K;

void solve()
{
    cin >> n >> K;
    ll S = 0, ans = -1, u = -1;
    map<ll, ll> cnt; cnt[0] = 0;
    for(int i=1; i<=n; i++)
    {
        ll x;
        cin >> x;
        S += x - K;
        if (cnt[S] || S == 0)
        {
            if (ans < i - cnt[S])
            {
                ans = i - cnt[S];
                u = cnt[S];
            }
        } else
        {
            cnt[S] = i;
        }
    }
    if (ans == -1) cout << 0;
     else cout << u + 1 << " " << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
