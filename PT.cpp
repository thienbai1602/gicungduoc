#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll tc, a, b, c, x, y;

ll gcd(ll a, ll b)
{
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while(b1)
    {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - x1 * q);
        tie(y, y1) = make_tuple(y1, y - y1 * q);
        tie(a1, b1) = make_tuple(b1, a1 - b1 * q);
    }
    return a1;
}

void solve()
{
    cin >> a >> b >> c;
    ll g = (a == 0 || b == 0 ? (a == 0 ? b : a) : gcd(a, b));
    if (c % g)
    {
        cout << 0 << "\n";
    } else
    {
        ll t = ((c * x) / g
        cout << (c * x) / g + b / g * t << " " << (c * y) / g  - a / g * t<< "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
