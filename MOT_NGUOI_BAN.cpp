#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6 + 66;

int n;
int cnt[mxN];

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        if (x <= n) ++cnt[x];
    }

    for(int i=1; i<=n+1; i++)
    {
        if (!cnt[i])
        {
            cout << i;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
