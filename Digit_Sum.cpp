/*#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

int tc;
ll A, B, dp[25][2];
vector<ll> pw(16);

ll recur(ll prev, ll cur, vector<int>&num, int N, bool tight)
{
    if (N == 0) return 0;
    if (dp[N][tight] != -1) return dp[N][tight];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        if (tight & (digit == limit))
        {
            ll X = cur * 10 + digit;
            ans += recur(prev, cur * 10 + digit, num, N - 1, 1) + (prev - X * pw[N - 1] + 1) * digit;
        } else
        {
            ans += recur(prev, cur * 10 + digit, num, N - 1, 0) + digit * pw[N - 1];
        }
    }
    return dp[N][tight] = ans;
}

ll sol(ll X)
{
    ll tmp = X;
    vector<int> num;
    while(X > 0)
    {
        num.push_back(X % 10);
        X /= 10;
    }
    reverse(num.begin(), num.end());
    memset(dp, -1, sizeof(dp));
    return recur(tmp, 0, num, sz(num), 1);
}

void solve()
{
    cin >> A >> B;
    pw[0] = 1;
    for(int i=1; i<16; i++)
    {
        pw[i] = pw[i - 1] * 10;
    }
    cout << sol(B) - sol(A - 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}*/
#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

ll A, B, pw[15], dp[15][2];

ll recur(vector<int>& num, int N, ll prev, ll cur, bool tight)
{
    if (N == 0)
    {
        return 0;
    }

    if (dp[N][tight] != -1) return dp[N][tight];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        if (tight && (digit == limit))
        {
            ll nxt = cur * 10 + digit;
            ans += digit * (prev - nxt * pw[N - 1] + 1) + recur(num, N - 1, prev, cur * 10 + digit, 1);
            //cout << cur << " " << N << " " << digit << " " << digit * (prev - nxt * pw[N - 1] + 1) << "\n";
        } else
        {
            ans += digit * pw[N - 1] + recur(num, N - 1, prev, cur * 10 + digit, 0);
            //cout << cur << " " << N << " " << digit << " " << digit * pw[N - 1] << "\n";
        }
    }
    return dp[N][tight] = ans;
}

ll sol(ll X)
{
    ll tp = X;
    vector<int> num;
    while(X > 0)
    {
        num.push_back(X % 10);
        X /= 10;
    }
    reverse(num.begin(), num.end());
    memset(dp, -1, sizeof(dp));
    return recur(num, sz(num), tp, 0, 1);
}

void solve()
{
    cout << sol(B) - sol(A - 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    pw[0] = 1;
    for(int i=1; i<15; i++)
    {
        pw[i] = (pw[i - 1] * 10);
    }
    while(cin >> A >> B)
    {
        if (A == -1 && B == -1) break;
        solve();
    }
    return 0;
}
