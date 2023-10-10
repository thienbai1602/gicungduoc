#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e6+ 66;

int tc, n;
ll d[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> d[i];
    }

    map<ll, ll> ma;
    ll a = 0, b = 0;
    for(int i=0; i<n; i++)
    {
        if (++ma[d[i]] % 2 == 0)
        {
            if (a <= d[i])
            {
                b = a;
                a = d[i];
            } else
            {
                b = max(b, d[i]);
            }
        }
    }
    cout << (a == 0 || b == 0 ? -1 : a * b) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
