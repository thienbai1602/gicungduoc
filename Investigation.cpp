#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

int tc;
ll A, B, K, dp[15][95][95][2];

ll recur(vector<int> &num, int N, ll cur, int s, bool tight)
{
    if (N == 0)
    {
        return (cur == 0 && s == 0);
    }

    if (dp[N][cur][s][tight] != -1) return dp[N][cur][s][tight];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        ans += recur(num, N - 1, (cur * 10 + digit) % K, (s + digit) % K, tight && (digit == limit));
    }
    return dp[N][cur][s][tight] = ans;
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
    cin >> A >> B >> K;
    if (K > 90)
    {
        cout << 0 << "\n";
        return;
    }
    cout << sol(B) - sol(A - 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    for(int i=0; i<tc; i++)
    {
        cout << "Case " << i + 1 << ": ";
        solve();
    }
    return 0;
}
