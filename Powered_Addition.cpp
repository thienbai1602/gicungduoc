#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int tc, n;

void solve()
{
    cin >> n;
    ll mx = -(1LL << 50), dif = 0;
    cout << mx;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        mx = max(mx, x);
        dif = max(dif, mx - x);
    }

    ll ans = 0;
    while((1LL << ans) <= dif)
    {
        ans++;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
