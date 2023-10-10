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

int n;
ll dp[mxN], cnt[mxN];

void solve()
{
    cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        if (cnt[x]++ == 0) a.pb(x);
    }

    sort(all(a));
    dp[0] = 0;
    dp[1] = a[0] * cnt[a[0]];
    for(int i=2; i<=sz(a); i++)
    {
        if (a[i - 1] != a[i - 2] + 1)
        {
            dp[i] = dp[i - 1] + a[i - 1] * cnt[a[i - 1]];
        } else
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i - 1] * cnt[a[i - 1]]);
        }
    }
    cout << dp[sz(a)];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

