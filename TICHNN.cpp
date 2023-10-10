#include    <bits/stdc++.h>
//#define SKY
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
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int N;
multiset<ll> store;

void solve()
{
    cin >> N;
    vector<ll> a(N);
    for(int i=0; i<N; i++)
    {
        cin >> a[i];
    }

    ll ans = inf;
    for(int i=N-1; i>=0; i--)
    {
        store.insert(a[i]);
        auto iter = store.upper_bound(a[i]);
        if (iter == store.end()) continue;
        if (a[i] <= 0) ans = min(ans, a[i] * (*store.rbegin()));
         else ans = min(ans, a[i] * (*iter));
    }

    if (ans == inf) cout << "NO";
     else cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif //SKY
    solve();
    return 0;
}
