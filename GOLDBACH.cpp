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

int tc;
ll N;

bool prime(ll X)
{
    if (X < 2) return false;
    for(ll i=2; i*i<=X; i++)
    {
        if (X % i == 0) return false;
    }
    return true;
}

void solve()
{
    cin >> N;
    for(ll x=2; x<=N/2; x++)
    {
        if (prime(x) && prime(N - x))
        {
            cout << x << " " << N - x << "\n";
            return;
        }
    }
    cout << "NO\n";
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
