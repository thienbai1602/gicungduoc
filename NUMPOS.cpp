#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll K;

void solve()
{
    cin >> K;
    if (K < 4)
    {
        cout << 1;
    } else
    {
        cout << (K - 2) * 3;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("NUMPOS.INP", "r", stdin);
    freopen("NUMPOS.OUT", "w", stdout);
    solve();
    return 0;
}
