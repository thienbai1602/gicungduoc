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
const int mxN = 1e5 + 66;

int N, Q;
ll a[mxN], f[mxN], g[mxN], mx[mxN];

void solve()
{
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cin >> a[i];
    }

    mx[N] = a[N]; f[N] = g[N] = 0;
    for(int i=N-1; i>0; i--)
    {
        mx[i] = max(mx[i + 1], a[i]);
        f[i] = mx[i] - a[i];
        g[i] = g[i + 1] + f[i];
    }

    cin >> Q;
    while(Q--)
    {
        int t;
        cin >> t;
        cout << g[t] << "\n";
    }
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
