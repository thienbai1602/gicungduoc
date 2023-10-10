#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5 + 66;

int n;
ll a[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int ret = 1, cur = 1;
    for(int i=1; i<n; i++)
    {
        if (a[i] * a[i - 1] < 0) cur++;
         else
         {
             ret = max(ret, cur);
             cur = 1;
         }
    }
    cout << max(ret, cur);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("DANDAU.INP", "r", stdin);
    freopen("DANDAU.OUT", "w", stdout);
    solve();
    return 0;
}
