#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e4 + 66;

int n;
ll a[mxN];

bool check(ll X)
{
    ll nxt = X;
    while(nxt > 0)
    {
        int digit = nxt % 10;
        if (digit == 0 || X % digit != 0) return false;
        nxt /= 10;
    }
    return true;
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    vector<ll> res;
    for(int i=0; i<n; i++)
    {
        if (check(a[i]))
        {
            res.push_back(a[i]);
        }
    }

    cout << sz(res) << "\n";
    for(int i=0; i<sz(res); i++)
    {
        cout << res[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("SOCHIAHET.INP", "r", stdin);
    freopen("SOCHIAHET.OUT", "w", stdout);
    solve();
    return 0;
}
