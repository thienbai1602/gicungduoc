#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int n, a[mxN];

void solve()
{
    cin >> n;
    int t = 0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        t += a[i];
    }

    int ret = INT_MIN;
    for(int i=0; i<n-1; i++)
    {
        int tp = t - a[i] - a[i + 1];
        ret = max(ret, tp + (-1) * a[i] + (-1) * a[i + 1]);
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
