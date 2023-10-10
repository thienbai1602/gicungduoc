#include    <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

ll l, r;

vector<int> pt(ll X)
{
    vector<int> ret;
    for(; X>0; X/=2)
    {
        ret.pb(X % 2);
    }
    return ret;
}

void solve()
{
    cin >> l >> r;
    vector<int> a = pt(l);
    vector<int> b = pt(r);
    while(sz(a) < sz(b)) a.pb(0);
    reverse(all(a)), reverse(all(b));

    for(int i=0, tight=1; i<sz(a); i++)
    {
        if (a[i] == b[i])
        {
            if (tight) continue;
            if (a[i] == 0) a[i] = 1;
             else b[i] = 0;
        }

        tight = (tight && a[i] == b[i]);
    }

    ll ret = 0;
    for(int i=0; i<sz(a); i++)
    {
        ret = (ret * 2 + (a[i] ^ b[i]));
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
