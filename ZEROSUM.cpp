#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 2e5 + 66;

int n;
ll a[mxN];
map<ll, ll> ma;

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ma[0] = 1;
    ll ret = 0, t = 0;
    for(int i=0; i<n; i++)
    {
        t += a[i];
        ret += ma[t]++;
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
