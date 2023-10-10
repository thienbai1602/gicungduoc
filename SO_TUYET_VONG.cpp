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
const ll MOD = 1234567891;
const int mxN = 1e6 + 66;

int tc;
vector<ll> pw;
ll L, R, K;
ii dp[19][1 << 11][11][2];

ii recur(vector<int> &num, int N, int mask, bool leading, bool tight)
{
    if (N == 0)
    {
        return mp(0, (__builtin_popcount(mask) == K));
    }

    if (!tight && dp[N][mask][K][leading].se != -1) return dp[N][mask][K][leading];

    ll S = 0, cnt = 0;
    int limit = tight ? num[N - 1] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        bool newLeading = leading && (digit == 0);
        if (__builtin_popcount(mask | (1 << digit)) > K) continue;
        ii cur = recur(num, N - 1, (newLeading ? 0 : mask | (1 << digit)), newLeading && digit == 0, tight && (digit == limit));
        //if (X == 0 && digit == 1) cout << cur.fi  << " " << cur.se << "\n";
        (S += cur.fi + cur.se * digit * pw[N - 1]) %= MOD;
        (cnt += cur.se) %= MOD;
    }

    if (!tight)
    {
       dp[N][mask][K][leading] = mp(S, cnt);
    }
    return mp(S, cnt);
}

ll sol(ll X)
{
    vector<int> num;
    while(X)
    {
        num.pb(X % 10);
        X /= 10;
    }
    return recur(num, sz(num), 0, 1, 1).fi % MOD;
}

void solve()
{
    cin >> L >> R >> K;
    cout << (sol(R) - sol(L - 1) + MOD) % MOD << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    pw.assign(20, 0);
    for(int i=0; i<20; i++)
    {
        pw[i] = (i == 0 ? 1 : pw[i - 1] * 10) % MOD;
    }

    for(int i=0; i<19; i++)
    {
        for(int j=0; j<(1 << 11); j++)
        {
            for(int k=0; k<11; k++)
            {
                for(int t=0; t<2; t++)
                {
                    dp[i][j][k][t] = mp(0, -1);
                }
            }
        }
    }

    cin >> tc;
    while(tc--) solve();
    return 0;
}

