#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 2e5 + 66;
const int mxa = 2e6 + 66;

int n, a[mxN], ma[mxa];

void solve()
{
    cin >> n;
    memset(ma, 0, sizeof(ma));
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        ma[a[i]] = a[i];
    }

    for(int i=1; i<=2e6; i++)
    {
        ma[i] = max(ma[i], ma[i - 1]);
    }

    sort(a, a + n);

    int ret = 0;
    for(int i=0; i<n; i++)
    {
        if (i > 0 && a[i] == a[i - 1]) continue;
        for(int j=a[i]*2; j<=2e6; j+=a[i])
        {
            ret = max(ret, ma[j - 1] % a[i]);
        }
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
