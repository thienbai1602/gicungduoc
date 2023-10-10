#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int tc, n;
ll X, a[mxN];

void solve()
{
    cin >> n >> X;
    ll S = X, mx = 0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        S += a[i];
        mx = max(mx, a[i]);
    }

    if (S % (n + 1) != 0 || mx > X)
    {
        cout << "NO\n";
        return;
    }

    ll dif = X - mx;
    for(int i=0; i<n; i++)
    {
        if (a[i] < mx)
        {
            dif -= mx - a[i];
        }
    }

    if (dif >= 0 && dif % (n + 1) == 0)
    {
        cout << "YES\n";
    } else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CANDY.INP", "r", stdin);
    freopen("CANDY.OUT", "w", stdout);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
