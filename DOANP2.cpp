#include    <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair<ll, ll>
using namespace std;

const int mxN = 1e5 + 66;

int n;
ii a[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }

    sort(a, a + n);

    ll ret = 0, st = a[0].fi, ed = a[0].se;
    for(int i=1; i<n; i++)
    {
        if (a[i].fi <= ed)
        {
            ed = max(ed, a[i].se);
        } else
        {
            ret += ed - st;
            st = a[i].fi, ed = a[i].se;
        }
    }
    ret += ed - st;
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
