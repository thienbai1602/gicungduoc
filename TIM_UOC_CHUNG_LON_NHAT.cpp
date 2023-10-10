#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 66;

int n, cnt[mxN];

void solve()
{
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        ++cnt[x];
    }

    ll ans = 1;
    for(int x=2; x<=(ll)1e6; x++)
    {
        int sl = 0;
        for(int j=x; j<=(ll)1e6; j+=x)
        {
            sl += cnt[j];
        }
        if (sl > 1) ans = x;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
