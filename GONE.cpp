#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

int tc;
ll A, B, dp[15][100][2];
vector<bool> prime(101, false);

void sieve()
{
    prime[0] = prime[1] = true;
    for(int i=2; i * i<=100; i++)
    {
        if (!prime[i])
        {
            for(int j=i*i; j<=100; j+=i)
            {
                prime[j] = true;
            }
        }
    }
}

ll recur(vector<int>& num, int N, int s, bool tight)
{
    if (N == 0)
    {
        return !prime[s];
    }

    if (dp[N][s][tight] != -1) return dp[N][s][tight];

    ll ans = 0;
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        ans += recur(num, N - 1, s + digit, tight && (digit == limit));
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
    return recur(num, sz(num), 0, 1);
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
    sieve();
    while(tc--) solve();
    return 0;
}
