#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int n;
ll a[mxN], pref[mxN], mi[mxN];

bool check(int K)
{
    for(int i=K; i<=n; i++)
    {
        if (pref[i] - mi[i - K] >= 0) return true;
    }
    return false;
}

int bs(int l, int r)
{
    int ans = -1;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (check(m))
        {
            ans = m;
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    memset(pref, 0, sizeof(pref));
    for(int i=0; i<n; i++)
    {
        pref[i + 1] = pref[i] + a[i];
    }

    mi[0] = 0;
    for(int i=0; i<n; i++)
    {
        mi[i + 1] = min(mi[i], pref[i + 1]);
    }
    cout << bs(1, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
