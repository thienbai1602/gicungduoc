#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 20;

int n;
ll l, r, x, a[mxN];

void solve()
{
    cin >> n >> l >> r >> x;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll ret = 0;
    for(int i=0; i<(1 << n); i++)
    {
        ll S = 0;
        multiset<ll> mst;
        for(int j=0; j<n; j++)
        {
            if (i & (1 << j))
            {
                mst.insert(a[j]);
                S += a[j];
            }
        }
        ret += (sz(mst) > 1) && (S >= l) && (S <= r) && (*mst.rbegin() - *mst.begin() >= x);
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
