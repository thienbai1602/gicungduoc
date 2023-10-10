#include    <bits/stdc++.h>
#define ll unsigned long long
#define sz(x) (int)x.size()
#define mp make_pair
#define ii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int mxN = 1e5 + 66;

ll n, p, K;
ll t[mxN];

bool check(ll X)
{
    ll ct = 0;
    for(int i=0; i<n; i++)
    {
        ll tp = X / t[i], ms = tp / (ll) (p + 1);
        ct += tp - ms;
    }
    return ct >= K;
}

ll bs(ll l, ll r)
{
    ll ans = 0;
    while(l <= r)
    {
        ll m = l + (r - l) / 2;
        if (check(m))
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> K >> p;
    for(int i=0; i<n; i++)
    {
        cin >> t[i];
    }
    cout << bs(1, 4e18);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
