#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int tc, n;

void solve()
{
    cin >> n;
    ll ans = (1 << 31) - 1;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        if (x != i) ans &= x;
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
