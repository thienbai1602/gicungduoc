#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define pb push_back
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(), x.end()
using namespace std;

const ll MOD = 1e9 + 7;
const int mxN = 5e3 + 200;

int tc;
vector<int> num;
bool LCM[mxN][165];
ii dp[19][mxN][165];
ll l, r, p[10], pw[19];

ii recur(vector<int> num, int N, int wibu, int S, bool tight)
{
    if (N == 0)
    {
        if (LCM[wibu][S])
        {
            return mp(0, 1);
        }
        return mp(0, 0);
    }

    if (dp[N][wibu][S].se != -1 && !tight) return dp[N][wibu][S];

    ii ans = mp(0, 0);
    int limit = tight ? num[sz(num) - N] : 9;
    for(int digit=0; digit<=limit; digit++)
    {
        ii nxt = recur(num, N - 1, wibu + p[digit], S + digit, tight && (digit == limit));
        ans.fi = ((ans.fi + nxt.fi) % MOD + (pw[N - 1] * digit * nxt.se) % MOD) % MOD;
        ans.se = (ans.se + nxt.se) % MOD;
    }
    if (!tight) dp[N][wibu][S] = ans;
    return ans;
}

ll sol(ll X)
{
    num.clear();
    while(X > 0)
    {
        num.pb(X % 10);
        X /= 10;
    }
    reverse(all(num));
    return recur(num, sz(num), 0, 0, 1).fi;
}

void init()
{
    p[0] = 0; pw[0] = 1;
    for(int x=1; x<=9; x++)
    {
        p[x] = p[x - 1] + (x * x);
    }

    for(int i=1; i<=18; i++)
    {
        pw[i] = (pw[i - 1] * 10) % MOD;
    }

    for(int sum1=0; sum1<=5131; sum1++)
    {
        for(int sum2=0; sum2<=163; sum2++)
        {
            LCM[sum1][sum2] = (__gcd(sum1, sum2) == 1);
        }
    }

    for(int i=0; i<=18; i++)
    {
        for(int j=0; j<=5131; j++)
        {
            for(int k=0; k<=163; k++)
            {
                dp[i][j][k] = mp(0, -1);
            }
        }
    }
}

void solve()
{
    cin >> l >> r;
    cout << (sol(r) - sol(l - 1) + MOD) % MOD << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc; init();
    while(tc--) solve();
    return 0;
}
