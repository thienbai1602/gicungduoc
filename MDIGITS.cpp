#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

ll A, B;
ll pw[15], dp[15][2][2];

ll recur(vector<int>& num, int N, int K, ll prev, ll cur, bool leading, bool tight)
{
    if (N == 0)
    {
        return 0;
    }

    if (dp[N][leading][tight] != -1) return dp[N][leading][tight];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;

    if (leading)
    {
        ans += recur(num, N - 1, K, prev, cur, 1, 0);
    }

    for(int digit=0; digit<=limit; digit++)
    {
        if (leading && digit == 0) continue;
        if (digit == K)
        {
            if (tight && (digit == limit))
            {
                ll nxt = cur * 10 + digit;
                ans += (prev - nxt * pw[N - 1] + 1);
            } else
            {
                ans += pw[N - 1];
            }
        }
        ans += recur(num, N - 1, K, prev, cur * 10 + digit, 0,  tight && (digit == limit));
    }
    return dp[N][leading][tight] = ans;
}

vector<int> trade(ll X)
{
    vector<int> num;
    while(X > 0)
    {
        num.push_back(X % 10);
        X /= 10;
    }
    reverse(num.begin(), num.end());
    return num;
}

ll sol(vector<int>& num, ll X, int K)
{
    memset(dp, -1, sizeof(dp));
    return recur(num, sz(num), K, X, 0, 1, 1);
}

void solve()
{
    if (A > B) swap(A, B); --A;
    ll tpA = A, tpB = B;
    vector<int> numA = trade(A);
    vector<int> numB = trade(B);
    for(int number=0; number<=9; number++)
    {
        cout << sol(numB, tpB, number) - sol(numA, tpA, number) << (number < 9 ? " " : "\n");
    }
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
        if (A == 0 && B == 0) break;
        solve();
    }
    return 0;
}
