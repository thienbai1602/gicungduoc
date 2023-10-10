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
const int mxN = 5e3 + 66;

int n, m, sz, pi[mxN], dp[mxN];
string A;

void solve()
{
    cin >> n >> m >> A;
    pi[0] = 0;
    for(int i=1, j=0; i<n; i++)
    {
        while(j > 0 && A[i] != A[j])
        {
            j = pi[j - 1];
        }
        j += (A[i] == A[j]);
        pi[i] = j;
    }

    set0(dp);
    dp[0] = 1; sz = min(m, m - n);
    for(int i=1; i<=sz; i++)
    {
        for(int j=min(n, i); j>0; j--)
        {
            if (!pi[j - 1])
            {
                dp[i] = (dp[i - j] + dp[i]) % MOD;
            }
        }
    }
    cout << dp[sz];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
