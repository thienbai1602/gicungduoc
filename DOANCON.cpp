#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 66;

int tc, n;
ll a[mxN], cnt[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    memset(cnt, 0, sizeof(cnt));
    int ct = 1;
    cnt[n - 1] = 1;
    for(int i=n-2; i>=0; i--)
    {
        if (a[i] * a[i + 1] < 0)
        {
            cnt[i] = ++ct;
        } else
        {
            cnt[i] = (ct = 1);
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << cnt[i] << (i < n - 1 ? " " : "\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
