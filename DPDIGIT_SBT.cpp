#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

ll A, B, dp[20][100][800][2];

ll recur(vector<int>& num, int N, int s, int sq, bool tight)
{
    if (N == 0)
    {
        if (s * sq != 0 && __gcd(s, sq) == 1) return 1;
         else return 0;
    }

    if (dp[N][s][sq][tight] != -1) return dp[N][s][sq][tight];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        ans += recur(num, N - 1, s + digit, sq + digit * digit, tight && (digit == limit));
    }
    return dp[N][s][sq][tight] = ans;
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
    return recur(num, sz(num), 0, 0, 1);
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
