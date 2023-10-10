#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int n;
ll a[mxN], mi[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    mi[n - 1] = a[n - 1];
    for(int i=n-2; i>=0; i--)
    {
        mi[i] = min(mi[i + 1], a[i]);
    }

    ll ret = LLONG_MIN;
    for(int i=0; i<n-1; i++)
    {
        ret = max(ret, a[i] - mi[i + 1]);
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
