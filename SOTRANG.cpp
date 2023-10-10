#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, pw_10[15], pw_9[15];

ll check(ll X)
{
    ll ret = 0;
    for(int i=0; i<=4; i++)
    {
        if (pw_10[i] > X) break;
        ret += (i == 0 ? min(1LL * 6, X - 3) : min(1LL * (X - pw_10[i] + 1) * (i + 1), 1LL * (pw_9[i] - pw_10[i] + 1) * (i + 1)));
    }
    return ret;
}

ll bs(ll l, ll r)
{
    ll ans = -1;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (check(m) <= N)
        {
            ans = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> N;
    pw_10[0] = 1, pw_9[0] = 9;
    for(int i=1; i<=4; i++)
    {
        pw_10[i] = pw_10[i - 1] * 10;
        pw_9[i] = pw_9[i - 1] * 10 + 9;
    }
    cout << bs(4, 1e4) << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
