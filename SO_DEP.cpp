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
const int mxN = 1e5 + 66;

int n, pi[mxN], nxt[mxN][10];
string l, r, k;
vector<int> L, R, K;
vector<vector<ll>> dp[2][2];

ll sol(vector<int> &num, int N, int suffixMatch, bool kExist, bool tight)
{
    if (N == sz(num))
    {
        return kExist;
    }

    if (dp[tight][kExist][N][suffixMatch] != -1) return dp[tight][kExist][N][suffixMatch] % MOD;

    ll ans = 0;
    int limit = tight ? num[N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        (ans += sol(num, N + 1, nxt[suffixMatch][digit], kExist | (nxt[suffixMatch][digit] == n), tight && (digit == limit))) %= MOD;
    }
    return dp[tight][kExist][N][suffixMatch] = ans % MOD;
}

void solve()
{
    cin >> l >> r >> k;
    n = sz(k);

    for(int i=0; i<sz(l); i++)
    {
        L.pb(l[i] - '0');
    }

    for(int i=0; i<sz(r); i++)
    {
        R.pb(r[i] - '0');
    }

    for(int i=0; i<sz(k); i++)
    {
        K.pb(k[i] - '0');
    }

    pi[0] = 0;
    for(int i=1, j=0; i<n; i++)
    {
        while(j > 0 && K[i] != K[j])
        {
            j = pi[j - 1];
        }
        j += (K[i] == K[j]);
        pi[i] = j;
    }

    for(int i=0; i<n; i++)
    {
        for(int digit=0; digit<10; digit++)
        {
            if (K[i] == digit) nxt[i][digit] = i + 1;
             else if (i > 0) nxt[i][digit] = nxt[pi[i - 1]][digit];
        }
    }

    for(int i=sz(l)-1; i>=0; i--)
    {
        --L[i];
        if (L[i] >= 0) break;
        L[i] = 9;
    }

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            dp[i][j].resize(sz(r));
            for(int l=0; l<sz(r); l++)
            {
                dp[i][j][l].resize(min(l, n) + 2, -1);
            }
        }
    }

    ll ansL = sol(L, 0, 0, 0, 1);
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int l=0; l<sz(R); l++)
            {
                dp[i][j][l].assign(min(l, n) + 2, -1);
            }
        }
    }
    ll ansR = sol(R, 0, 0, 0, 1);
    cout << (ansR - ansL + MOD * MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
