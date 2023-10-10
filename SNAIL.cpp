#include    <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll a, b, v;

void solve()
{
    cin >> a >> b >> v;
    cout << (v >= a ? (ll)ceil((ld)(v - a) / (ld)(a - b)) + 1 : 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
