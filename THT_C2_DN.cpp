#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 66;

int n;
ll a[mxN], mx[mxN], mi[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    mx[0] = a[0];
    for(int i=1; i<n; i++)
    {
        mx[i] = max(mx[i - 1], a[i]);
    }

    mi[n - 1] = a[n - 1];
    for(int i=n-2; i>=0; i--)
    {
        mi[i] = min(mi[i + 1], a[i]);
    }

    ll ret = LLONG_MIN;
    for(int i=1; i<n-1; i++)
    {
        ret = max(ret, 3 * mx[i - 1] + 2 * a[i] - 5 * mi[i + 1]);
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
