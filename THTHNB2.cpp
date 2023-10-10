#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e18;
const int mxN = 5e3 + 66;

ll n, T;
ll a[mxN];

void solve()
{
    cin >> n >> T;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    T *= 3;
    sort(a, a + n);

    ll diff = INF, ans = -1;
    for(int i=0; i<n-2; i++)
    {
        for(int j=i+1; j<n-1; j++)
        {
            ll X = T - a[i] - a[j];
            int ps = lower_bound(a + j + 1, a + n, X) - a;
            if (ps != n)
            {
                if (diff > abs(T - (a[i] + a[j] + a[ps])))
                {
                    diff = abs(T - (a[i] + a[j] + a[ps]));
                    ans = a[i] + a[j] + a[ps];
                }
            }

            --ps;
            if (ps > j)
            {
                if (diff > abs(T - (a[i] + a[j] + a[ps])))
                {
                    diff = abs(T - (a[i] + a[j] + a[ps]));
                    ans = a[i] + a[j] + a[ps];
                }
            }

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
