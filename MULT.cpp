#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int tc;
ll A, B;

void solve()
{
    cin >> A >> B;
    cout << B / A << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("MULT.INP", "r", stdin);
    freopen("MULT.OUT", "w", stdout);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
