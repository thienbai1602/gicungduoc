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
const int mxN = 1e6 + 66;

ll p;
int n, k;

void solve()
{
    cin >> n >> k >> p;
    vector<ll> a(n), b(k);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<k; i++)
    {
        cin >> b[i];
    }

    sort(all(a)), sort(all(b));
    ll ans = inf;
    for(int i=0; i<=k-n; i++)
    {
        ll cur = 0;
        for(int j=0; j<n; j++)
        {
            cur = max(cur, abs(p - b[i + j]) + abs(b[i + j] - a[j]));
        }
        ans = min(ans, cur);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
