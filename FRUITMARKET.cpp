#include    <bits/stdc++.h>
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int n;
ll a[mxN], m;

void solve()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    queue<ll> pq;
    while(1)
    {
        ll nxt = 0, cnt = 0;
        for(int i=0; i<n; i++)
        {
            if (a[i] + nxt <= m)
            {
                nxt += a[i];
                ++cnt;
            }
        }

        if (!cnt) break;
        ans += (m / nxt) * cnt;
        m -= (m / nxt) * nxt;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

