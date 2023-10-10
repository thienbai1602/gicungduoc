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

int n;
ll a[mxN], sq[mxN], S[mxN], T[mxN];

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        S[i] = (S[i - 1] + a[i]) % 7;
        T[i] = (T[i - 1] + a[i] * S[i - 1]) % 7;
    }

    ll ans = 0;
    vector<vector<ll>> dp(7, vector<ll>(7, 0));
    for(int i=1; i<=n; i++)
    {
        ++dp[S[i - 1]][T[i - 1]];
        for(int j=0; j<7; j++)
        {
            for(int k=0; k<7; k++)
            {
                if ((T[i] - k - S[i] * j + j * j + 49) % 7 == 0)
                {
                    ans += dp[j][k];
                }
            }
        }
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
