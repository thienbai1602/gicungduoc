#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

int tc;
ll A, B, dp[10][100][100][2][2][2];

ll recur(vector<int>& num, int N, int s, int s_even, bool even, bool leading, bool tight)
{
    if (N == 0)
    {
        //cout << s << " " << s_even << " " << cur << "\n";
        return (2 * s_even - s == 1);
    }

    if (dp[N][s][s_even][even][leading][tight] != -1) return dp[N][s][s_even][even][leading][tight];

    ll ans = 0;
    if (leading)
    {
        ans += recur(num, N - 1, s, s_even, !even, 1, 0);
    }

    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        if ((leading && (digit == 0)) == 0)
        {
            ans += recur(num, N - 1, s + digit, even ? s_even + digit : s_even, !even, 0, tight && (digit == limit));
        }
    }
    return dp[N][s][s_even][even][leading][tight] = ans;
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
    return recur(num, sz(num), 0, 0, sz(num) % 2 == 0, 1, 1);
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
    cin >> tc;
    while(tc--) solve();
    return 0;
}
