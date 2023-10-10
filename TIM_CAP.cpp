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
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 2e6 + 66;

ll V;
int N, K;

ll calc(int m)
{
    ll ret = 0;
    for(int x=1; x<=min(N, m-1); x++)
    {
        int g = __gcd(x, K);
        //cout << x << " " << min((ll)N, m-x) / (K / g) << "\n";
        ret += min(N, m - x) / (K / g);
    }
    return ret;
}

void solve()
{
    cin >> N >> K >> V;
    int l = 2, r = N << 1, ans = -1;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        if (calc(m) >= V)
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }

    ll cnt = calc(ans - 1);
    //cout << ans << " " << calc(ans) << "\n";
    for(int x=1; x<=min(N, ans - 1); x++)
    {
        if ((ll)x * (ans - x) % K == 0 && ans - x <= N)
        {
            ++cnt;
        }

        if (cnt == V)
        {
            cout << x << " " << ans-x;
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
