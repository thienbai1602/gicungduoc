#include    <bits/stdc++.h>
#define ll long long
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

ll N, K, ans = 1;

void solve()
{
    cin >> N >> K;
    ll x = 0;
    while(N % 2 == 0)
    {
        ++x;
        N /= 2;
    }

    for(ll i=max(0LL, K-x); i>0; i--)
    {
        ans *= 2;
    }

    x = 0;
    while(N % 5 == 0)
    {
        ++x;
        N /= 5;
    }

    for(ll i=max(0LL, K-x); i>0; i--)
    {
        ans *= 5;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("chiahet.inp", "r", stdin);
    freopen("chiahet.out", "w", stdout);
    solve();
    return 0;
}
