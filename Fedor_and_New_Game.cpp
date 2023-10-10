#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e3 + 66;

int n, m, K;
ll a[mxN];

void solve()
{
    cin >> n >> m >> K;
    for(int i=0; i<=m; i++)
    {
        cin >> a[i];
    }

    int ret = 0;
    for(int i=0; i<m; i++)
    {
        if (__builtin_popcount(a[i] ^ a[m]) <= K) ret++;
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
