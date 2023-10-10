#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 2e5 + 66;
const int mxA = 1e6 + 66;

int n, ct[mxA];

void solve()
{
    cin >> n;
    int mx = 0;
    memset(ct, 0, sizeof(ct));
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        ++ct[x];
        mx = max(mx, x);
    }

    int ret = 1;
    for(int i=2; i<=mx; i++)
    {
        int cnt = 0;
        for(int j=i; j<=mx; j+=i)
        {
            cnt += ct[j];
        }
        if (cnt > 1) ret = max(ret, i);
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
