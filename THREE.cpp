#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, c;

void solve()
{
    cin >> a >> b >> c;
    ll ret = c;
    ll tp = min(a, b);
    ret += tp, a -= tp, b -= tp;
    cout << ret + a / 3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
