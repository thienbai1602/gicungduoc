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
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int n, Q;

void solve()
{
    cin >> n >> Q;
    vector<ll> a(n + 1);
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    vector<ll> s(n + 1, 0);
    for(int i=1; i<=n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    while(Q--)
    {
        int type, x, k;
        cin >> type >> x >> k;
        if (!type) cout << s[k] << "\n";
         else cout << s[x] - s[x - k] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
