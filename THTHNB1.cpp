#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e18;

ll L, R, T;

ll bs_left(ll l, ll r)
{
    ll ans = -INF;
    while(l <= r)
    {
        ll X = l + (r - l) / 2;
        if (X < T - X && T - X >= L && T - X <= R)
        {
            ans = X;
            r = X - 1;
        } else
        {
            l = X + 1;
        }
    }
    return ans;
}

ll bs_right(ll l, ll r)
{
    ll ans = -INF;
    while(l <= r)
    {
        ll X = l + (r - l) / 2;
        if (X < T - X && T - X >= L && T - X <= R)
        {
            ans = X;
            l = X + 1;
        } else
        {
            if (T - X > R) l = X + 1;
             else r = X - 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> L >> R >> T;
    ll ed = bs_right(L, R);
    ll st = bs_left(L, ed);
    cout << (ed == -INF ? 0 : (ed - st + 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
