#include    <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

const ld eps = 1e-9;
const ll mxN = 2e5 + 66;

int n, tc;
ll h[mxN], cost[mxN];

ll cal(ll cur_height)
{
    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += (abs(h[i] - cur_height) * cost[i]);
    }
    return ans;
}

ll bs(ll l, ll r)
{
    while(l < r)
    {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll cm1 = cal(m1), cm2 = cal(m2);

        if (cm1 < cm2)
        {
            r = m2 - 1;
        } else
        {
            if (cm1 > cm2) l = m1 + 1;
             else
             {
                 l = m1 + 1, r = m2 - 1;
             }
        }

    }
    return cal(l);
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> h[i];
    }

    for(int i=0; i<n; i++)
    {
        cin >> cost[i];
    }
    cout << bs(1, 2e5) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
