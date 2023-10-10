#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

int f[15][150];
ll A, B, dp[15][150][2];

bool check(ll X, int nxt)
{
    //cout << X << " " << nxt << "\n";
    ll tp = X;
    vector<int> number;
    while(tp > 0)
    {
        number.push_back(tp % 10);
        tp /= 10;
    }

    memset(f, -1, sizeof(f));

    f[0][0] = 1;
    for(int i=0; i<sz(number); i++)
    {
        for(int sum=nxt; sum>=0; sum--)
        {
            f[i + 1][sum] = f[i][sum];
            if (sum >= number[i])
            {
                if (f[i][sum - number[i]] > -1)
                {
                    f[i + 1][sum] = 1;
                }
            }
        }
    }
    //if (f[sz(number)][nxt / 2] > -1) cout << X << " " << nxt / 2 << " ";
    return f[sz(number)][nxt / 2] > -1;
}

ll recur(vector<int>& num, int N, ll cur, int s, bool tight)
{
    if (N == 0)
    {
        //if (check(cur, s) && s > 0) cout << cur << " ";
        return (s % 2 == 0 && s > 0 && check(cur, s));
    }

    if (dp[N][s][tight] != -1) return dp[N][s][tight];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        ans += recur(num, N - 1, cur * 10 + digit, s + digit, tight && (digit == limit));
    }
    return dp[N][s][tight] = ans;
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
    //cout << sol(B) - sol(A - 1) << "\n";
    cout << sol(B) - sol(A - 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(cin >> A >> B)
    {
        if (A == 0 && B == 0) break;
        solve();
    }
    return 0;
}
