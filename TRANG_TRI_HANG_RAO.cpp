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
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int n, m, pi[mxN];
ll a[mxN], b[mxN], diffA[mxN], diffB[mxN], dp[mxN];

void solve()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<m; i++)
    {
        cin >> b[i];
    }

    for(int i=0; i<n-1; i++)
    {
        diffA[i] = a[i + 1] - a[i];
    }

    for(int i=0; i<m-1; i++)
    {
        diffB[i] = b[i + 1] - b[i];
    }

    pi[0] = 0;
    for(int i=1, j=0; i<m-1; i++)
    {
        while(j > 0 && diffB[i] != diffB[j])
        {
            j = pi[j - 1];
        }
        j += (diffB[i] == diffB[j]);
        pi[i] = j;
    }

    int i = 0, j = 0;
    vector<bool> suit(n + 1, 0);
    while(i < n - 1)
    {
        if (diffA[i] == diffB[j] && a[i - j] >= b[0])
        {
            ++i, ++j;
            if (j == m - 2 || i == n - 1)
            {
                suit[i + 2] = 1;
            }
        } else if (j > 0) j = pi[j - 1];
         else ++i;
    }

    // dp[i] là số cách dán decal với i là vị trí kết thúc
    // +) i có thể dán decal ->
    // *) chọn i -> dp[i - m]
    vector<ll> pref(n + 1, 0);
    pref[0] = 1;
    for(int i=1; i<=n; i++)
    {
        if (suit[i])
        {
            (dp[i] += pref[max(i - m + 1, 0)]) %= MOD;
        }
        pref[i] = (pref[i - 1] + dp[i]) % MOD;
    }
    cout << (pref[n] - 1 + MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
