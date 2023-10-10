#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 66;

int n;
ll a[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    vector<ll> r(n + 1, 0);
    r[n - 1] = a[n - 1];
    for(int i=n-2; i>=0; i--)
    {
        r[i] = __gcd(a[i], r[i + 1]);
    }

    ll x = 0, ans = r[1];
    for(int i=0; i<n-1; i++)
    {
        x = __gcd(x, a[i]);
        ans = max(ans, __gcd(x, r[i + 2]));
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
