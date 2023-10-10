#include    <bits/stdc++.h>
#define ll long long
using namespace std;

ll A, B;

ll total(ll a, ll b)
{
    return (a + b) * (b - a + 1) / 2;
}

ll bs(ll left, ll right)
{
    ll l = left, r = right - 1;
    while(l < r)
    {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;

        ll ck1 = abs(total(left, m1) - total(m1 + 1, right));
        ll ck2 = abs(total(left, m2) - total(m2 + 1, right));

        if (ck1 > ck2)
        {
            l = m1 + 1;
        } else if (ck1 < ck2)
        {
            r = m2 - 1;
        } else
        {
            l = m1 + 1;
            r = m2 - 1;
        }
    }
    return (abs(total(left, l) - total(l + 1, right)) < abs(total(left, l + 1) - total(l + 2, right)) ? l : l + 1);
}

void solve()
{
    cin >> A >> B;
    cout << bs(A, B);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("DIFF.INP", "r", stdin);
    freopen("DIFF.OUT", "w", stdout);
    solve();
    return 0;
}
