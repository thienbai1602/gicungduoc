#include    <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;

ll x, y, ans = 0;

void solve()
{
    cin >> x >> y;
    vector<ll> s = {y, y, y};
    while(1)
    {
        sort(all(s));
        if (s[0] == x) break;
        s[0] = min(x, (s[1] + s[2] - 1));
        ans++;
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
