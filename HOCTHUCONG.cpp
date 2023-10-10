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
        cnt[x]++;
    }

    int ret = n;
    for(int i=0; i<2001; i++)
    {
        ret -= (cnt[i] / 3 * 3);
    }
    cout << (n - ret) / 3 << " " << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
