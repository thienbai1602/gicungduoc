#include    <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll a, b, c, g, x, y;

void euclid(ll a, ll b)
{
    if (b == 0)
    {
        g = a;
        x = 1, y = 0;
    } else
    {
        euclid(b, a % b);
        ll tp = x;
        x = y;
        y = tp - (a / b) * y;
    }
}

void solve()
{
    cin >> a >> b >> c;
    euclid(a, b);
    if (c % g != 0)
    {
        cout << 0;
    } else
    {
        ll A = -(x * c / b) + ((x * c) % b == 0 || (x * c) / b < 0);
        ll B = (y * c / a) - ((y * c) % a == 0 || (y * c) / a < 0);
        cout << max(0LL, B - A + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
