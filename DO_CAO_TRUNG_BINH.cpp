#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 66;

ll n, K, u;
map<ll, ll> cnt;
ll a[mxN], pref[mxN];

void solve()
{
    cin >> n >> K;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        a[i] -= K;
    }

    for(int i=1; i<=n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    cnt[0] = 1;
    ll u, v = -1;
    for(int i=1; i<=n; i++)
    {
        if (cnt[pref[i]])
        {
            if (v < (i - cnt[pref[i]] + 1))
            {
                v = i - cnt[pref[i]] + 1;
                u = cnt[pref[i]];
            }
        } else
        {
            cnt[pref[i]] = i + 1;
        }
    }

    if (v ==  -1)
    {
        cout << 0;
    } else
    {
        cout << u << " " << v;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
