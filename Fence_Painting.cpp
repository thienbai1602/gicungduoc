#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, c, d;

void solve()
{
    cin >> a >> b >> c >> d;
    if (b > d)
    {
        swap(b, d);
        swap(a, c);
    }

    ll ret = 0;
    if (c <= b)
    {
        ret = max(b, d) - min(a, c);
    } else
    {
        ret = (b - a) + (d - c);
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    solve();
    return 0;
}
