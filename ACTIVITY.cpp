#include    <bits/stdc++.h>
#define ll unsigned long long
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

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int tc;
ll m, n, k, a, b;

void solve()
{
    cin >> m >> n >> k >> a >> b;
    ll man = m / a, woman = n / b;
    ll gr = min(man, woman);
    ll remain = (m + n) - gr * (a + b);
    if (remain >= k) cout << gr << "\n";
     else
     {
         ll diff = k - remain, sz = a + b;;
         ll sl = diff / sz + (diff % sz > 0);
         cout << gr - sl << "\n";

     }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
