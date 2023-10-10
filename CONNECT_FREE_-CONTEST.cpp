#include    <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

const int mxN = 1e5 + 55;
const ll mod = 1e9 + 7;

int n;
pair<ll, ll> p[mxN];

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> p[i].fi;
        p[i].se = 0;
    }

    for(int i=0; i<n; i++)
    {
        cin >> p[i + n].fi;
        p[i + n].se = 1;
    }

    sort(p, p + 2 * n);

    ll ret = 1, cnt = 0;
    for(int i=0; i<2*n; i++)
    {
        if (p[i].se == 0)
        {
            if (cnt < 0) ret = (ret * (-cnt)) % mod;
            cnt++;
        } else
        {
            if (cnt > 0) ret = (ret * cnt) % mod;
            cnt--;
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
