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
const int mxN = 5e3 + 66;

int n, k;
vector<ii> a;

bool cmp(ii &x, ii &y)
{
    return (x.fi > y.fi || (x.fi == y.fi && x.se < y.se));
}

void solve()
{
    cin >> n >> k;
    a.assign(n, mp(0, 0));
    for(int i=0; i<n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }

    sort(all(a), cmp);
    vector<int> c(n, 0);
    for(int i=0; i<n; i++)
    {
        c[a[i].se] = i / k;
    }

    vector<int> dp(n, 0);
    dp[0] = 1;
    for(int i=1; i<n; i++)
    {
        int jmax = -1;
        for(int j=0; j<i; j++)
        {
            if (c[i] >= c[j])
            {
                if (jmax == -1 || dp[jmax] < dp[j])
                {
                    jmax = j;
                }
            }
        }
        dp[i] = (jmax == -1 ? 1 : dp[jmax] + 1);
    }

    int mx = 0;
    for(int i=0; i<n; i++)
    {
        mx = max(mx, dp[i]);
    }
    cout << n - mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}

