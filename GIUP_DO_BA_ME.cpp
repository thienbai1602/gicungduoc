#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll T, n, c[166];

void solve()
{
    cin >> T >> n;
    for(int i=0; i<n; i++)
    {
        cin >> c[i];
    }

    sort(c, c + n);

    ll ans = 0, cur = 0;
    for(int i=0; i<n; i++)
    {
        if (cur + c[i] > T) break;
        cur += c[i];
        ++ans;
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
