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
const int mxN = 1e7 + 66;

int N, K;
ll a[mxN];

void solve()
{
    cin >> N >> K;
    vector<ll> a(N);
    for(int i=0; i<N; i++)
    {
        cin >> a[i];
    }

    sort(all(a));
    ll ans = INF;
    for(int i=0; i<N-K+1; i++)
    {
        ans = min(ans, a[i+K-1] - a[i]);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CHOSEBOOK.INP", "r", stdin);
    freopen("CHOSEBOOK.OUT", "w", stdout);
    solve();
    return 0;
}
