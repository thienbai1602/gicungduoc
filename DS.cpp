#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

ll A, K;
ll dp[15][15][2][2];

ll recur(vector<int>& num, int N, int prev_digit, bool leading, bool tight)
{
    if (N == 0)
    {
        return (prev_digit == K);
    }

    if (dp[N][prev_digit][leading][tight] != -1) return dp[N][prev_digit][leading][tight];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        bool new_leading = leading && (digit == 0);
        ans += recur(num, N - 1, digit, leading && (digit == 0), tight && (digit == limit));
    }
    return dp[N][prev_digit][leading][tight] = ans;
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
    return recur(num, sz(num), -1, 1, 1);
}

void solve()
{
    cin >> A >> K;
    cout << sol(A - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("DS.INP", "r", stdin);
    //freopen("DS.OUT", "w", stdout);
    solve();
    return 0;
}
