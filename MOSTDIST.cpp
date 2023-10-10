#include    <bits/stdc++.h>
#define ld long double
using namespace std;

const int mxN = 1e6 + 55;

int n;
ld x[mxN], y[mxN];

ld sq(ld x)
{
    return x * x;
}

void solve()
{
    cin >> n;
    int sz_x = 0, sz_y = 0;
    for(int i=0; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == 0)
        {
            y[sz_y++] = v;
        } else
        {
            x[sz_x++] = u;
        }
    }

    sort(x, x + sz_x);
    sort(y, y + sz_y);
    ld ret = max({sq(x[sz_x - 1] - x[0]), sq(y[sz_y - 1] - y[0]), sq(y[sz_y - 1]) + sq(x[sz_x - 1]), sq(y[sz_y - 1]) + sq(x[0]), sq(y[0]) + sq(x[0]), sq(y[0]) + sq(x[sz_x - 1])});
    cout << fixed << setprecision(6) << sqrt(ret);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
