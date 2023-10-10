#include    <bits/stdc++.h>
#define ll long long
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

int tc, n;
ll cnt[70];

void solve()
{
    cin >> n;
    set0(cnt);
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        ++cnt[64 - __builtin_clzll(x)];
    }

    ll ret = 0;
    for(int i=0; i<65; i++)
    {
        if (cnt[i] > 1)
        {
            ret += (cnt[i] - 1) * cnt[i] / 2;
        }
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
