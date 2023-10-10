#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int tc, n;
ll ret;

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin >> x;
        ret = (i == 0 ? x : ret & x);
    }
    cout << ret << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
