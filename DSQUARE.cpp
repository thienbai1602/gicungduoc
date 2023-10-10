#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3 + 55;
const int mxN = 1e6 + 66;

ll l, r;
bool f[N];

void solve()
{
    cin >> l >> r;
    memset(f, false, sizeof(f));

    for(ll i=l; i<=r; i++)
    {
        for(ll j=2; j<=i; j++)
        {
            if (i % (j * j) == 0)
            {
                f[i - l] = true;
                break;
            }
        }
    }

    ll ret = 0;
    for(ll i=l; i<=r; i++)
    {
        for(ll j=i+1; j<=r; j++)
        {
            if (f[i - l] || f [j - l] || __gcd(i, j) > 1)
            {
                ret++;
            }
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
