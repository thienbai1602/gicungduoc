#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int n, m;
ll K, a[mxN], p[mxN];

ll check(ll X)
{
    ll cur = 0;
    for(int i=0; i<X; i++)
    {
        cur += max(0LL, p[i] - a[n-X+i]);
    }
    return cur;
}

ii bs(ll l, ll r)
{
    ii ans = mp(0, 0);
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        ll used = check(m);
        if (used <= K)
        {
            ans = mp(m, used);
            l = m + 1;
        } else
        {
            r = m - 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> m >> K;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int j=0; j<m; j++)
    {
        cin >> p[j];
    }

    sort(a, a + n);
    sort(p, p + m);

    ii ret = bs(0, min(n, m));
    cout << ret.fi << " " << ret.se;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}


