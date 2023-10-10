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
ll ans;
vector<int> v;
vector<ii> store;

void minimize(ll &a, const ll b)
{
    if (a > b) a = b;
}

void middle(int l, int r, ii f, bool ok)
{
    if (l > r)
    {
        if (ok)
        {
            int left = 0, right = sz(store) - 1, ret = -1;
            while(left <= right)
            {
                int m = (left + right) >> 1;
                if (store[m].fi >= -f.fi)
                {
                    ret = m;
                    right = m - 1;
                } else
                {
                    left = m + 1;
                }
            }
            if (-f.fi == store[ret].fi)
            {
                ans = min(ans, store[ret].se + f.se);
            }
        } else store.pb(f);
        return;
    }
    middle(l + 1, r, mp(f.fi + v[l], f.se), ok);
    middle(l + 1, r, mp(f.fi - v[l], f.se), ok);
    middle(l + 1, r, mp(f.fi, f.se + v[l]), ok);
}

void sub2()
{
    store.clear();
    v.assign(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }

    if (n == 1)
    {
        cout << v[0] << "\n";
        return;
    }

    ans = inf;
    middle(0, n / 2 - 1, mp(0, 0), 0);
    sort(all(store));
    middle(n / 2, n - 1, mp(0, 0), 1);
    cout << ans << "\n";
}

void sub4()
{
    int S = 0;
    v.assign(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
        S += v[i];
    }

    S /= 2;
    vector<vector<ll>> dp(2, vector<ll>(mxN, inf));
    dp[1][S] = 0;
    for(int i=0; i<n; i++)
    {
        int cur = (i & 1);
        int pre = !cur;
        for(int delta=-S; delta<=S; delta++)
        {
            dp[cur][delta + S] = inf;
            if (delta + v[i] <= S) minimize(dp[cur][delta + S], dp[pre][delta + S + v[i]]);
            if (delta - v[i] >= -S) minimize(dp[cur][delta + S], dp[pre][delta + S - v[i]]);
            minimize(dp[cur][delta + S], dp[pre][delta + S] + v[i]);
        }
    }
    cout << dp[(n - 1) & 1][S] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    while(cin >> n)
    {
        if (n <= 24) sub2();
         else sub4();
    }
    return 0;
}

