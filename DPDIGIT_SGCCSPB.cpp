#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

ll A, B, dp[20][2200][2][2];

ll recur(vector<int>& num, int N, int mask, bool leading, bool tight)
{
    if (N == 0)
    {
        return !leading;
    }

    if (dp[N][mask][leading][tight] != -1) return dp[N][mask][leading][tight];

    ll ans = 0;
    if (leading)
    {
        ans += recur(num, N - 1, 0, 1, 0);
    }

    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        if (!leading || digit != 0)
        {
            if ((mask & (1 << (digit + 1))) == 0)
            {
                ans += recur(num, N - 1, mask | 1 << (digit + 1), 0, tight && (digit == limit));
            }
        }
    }
    return dp[N][mask][leading][tight] = ans;
}

ll sol(ll X)
{
    vector<int> num;
    while(X > 0)
    {
        num.push_back(X % 10);
        X /= 10;
    }
    reverse(num.begin(), num.end());
    memset(dp, -1, sizeof(dp));
    return recur(num, sz(num), 0, 1, 1);
}

void solve()
{
    cin >> A >> B;
    cout << sol(B) - sol(A - 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
