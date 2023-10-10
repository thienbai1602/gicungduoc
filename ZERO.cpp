#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 66;

int n;
ll a[mxN];
map<ll, int> ms;

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int ret = 0;
    ms[0] = 0;
    ll S = 0;
    for(int i=0; i<n; i++)
    {
        S += a[i];
        if (S == 0 || ms[S] > 0)
        {
            ret = (S == 0 ? max(ret, i + 1) : max(ret, i + 1 - ms[S]));
        } else if (ms[S] == 0) ms[S] = i + 1;
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("ZERO.INP", "r", stdin);
    freopen("ZERO.OUT", "w", stdout);
    solve();
    return 0;
}
