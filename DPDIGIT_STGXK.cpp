#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const int mxN = 1e5 + 66;
const ll mod = 1e9 + 7;

int n, m;
string L, R;
ll dp[mxN][2][10][2][2];

ll recur(string& num, int N, bool leading, int prev_digit, bool increase, bool tight)
{
    if (N == 0)
    {
        return 1;
    }

    if (dp[N][leading][prev_digit][increase][tight] != -1) return dp[N][leading][prev_digit][increase][tight];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] - '0' : 9;
    if (!leading)
    {
        if (increase)
        {
            for(int digit=prev_digit+1; digit<=limit; digit++)
            {
                ans += recur(num, N - 1, 0, digit, 0, tight && (digit == limit));
            }
        } else
        {
            for(int digit=0; digit<=min(prev_digit - 1, limit); digit++)
            {
                ans += recur(num, N - 1, (digit == 0) && leading, digit, 1, tight && (digit == limit));

            }
        }
    } else
    {
        ans += recur(num, N - 1, 1, 0, 1, tight && (0 == limit));
        for(int digit=1; digit<=limit; digit++)
        {
            ans += recur(num, N - 1, 0, digit, 1, tight && (digit == limit));
            if (N > 1) ans += recur(num, N - 1, 0, digit, 0, tight && (digit == limit));
        }
    }
    return dp[N][leading][prev_digit][increase][tight] = ans % mod;
}

ll sol(string& X)
{
    if (sz(X) == 1) return X[0] - '0' + 1;
    memset(dp, -1, sizeof(dp));
    return recur(X, sz(X), 1, -1, 1, 1) % mod;
}

void decrease(string& L)
{
    int ps = sz(L) - 1;
    while(L[ps] == '0')
    {
        L[ps] = '9', ps--;
    }
    L[ps]--;
    while(L[0] == '0' && sz(L) > 0) L.erase(0, 1);
}

void solve()
{
    cin >> n >> m >> L >> R;
    decrease(L);
    cout << (sol(R) - sol(L) + mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
