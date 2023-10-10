#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e4 + 66;

int n;
ll a[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll ret = a[0];
    for(int i=1; i<n; i++)
    {
        ret = __gcd(ret, a[i]);
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("GAME.INP", "r", stdin);
    freopen("GAME.OUT", "w", stdout);
    solve();
    return 0;
}
