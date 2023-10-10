#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;

bool sf(ll x, ll y)
{
    ll S = 0;
    for(; x>0; x/=10)
    {
        S += (x % 10);
    }
    return S == y;
}

void solve()
{
    cin >> N;
    ll tp = 0, X = N;
    for(; X>0; X/=10)
    {
        tp += 9;
    }

    ll ans = 1e18;
    for(int x=1; x<=tp; x++)
    {
        ll g = (ll)sqrt(x * x + 4 * N);
        if (g * g == x * x + 4 * N)
        {
            if (g - x > 0 && (g - x) % 2 == 0)
            {
                if (sf((g - x) / 2, x))
                {
                    ans = min(ans, (g - x) / 2);
                }
            }
        }
    }
    cout << (ans == 1e18 ? -1 : ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
