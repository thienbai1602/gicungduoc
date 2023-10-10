#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 166;

ll n, H;
ll a[mxN];

void solve()
{
    cin >> n >> H;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        ll S = 0;
        for(int dis=0; dis<n; dis++)
        {
            S += a[i - dis] + (dis != 0 ? a[i + dis] : 0);
            if (i - dis < 0 || i + dis == n) break;
            if (dis * 3 <= H) ans = max(ans, S);
        }
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
