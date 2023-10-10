#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;

const ll mod = 1e9 + 9;

string S;
ll dp[20][2050], pw[15];

ll sol(int N, ll cur)
{
    if (N == 0)
    {
        return (cur % 2048 == 0);
    }

    if (dp[N][cur % 2048] != -1) return dp[N][cur % 2048];

    ll ans = 0;
    if (S[sz(S) - N] != '?')
    {
        ll tp =((int)S[sz(S) - N] - '0');
        ans += sol(N - 1, cur * 10 + tp);
    } else
    {
        for(int digit=0; digit<=9; digit++)
        {
            ans += sol(N - 1, cur * 10 + digit);
        }
    }
    return dp[N][cur % 2048] = ans;
}

void solve()
{
    cin >> S;
    memset(dp, -1, sizeof(dp));
    int sz = min(sz(S), 11);

    pw[0] = 1;
    for(int i=1; i<12; i++)
    {
        pw[i] = pw[i - 1] * 10;
    }

    ll ret = sol(sz, 0) % mod;
    if (sz(S) > 11)
    {
        for(int i=0; i<sz(S)-11; i++)
        {
            if (S[i] == '?') ret *= (10 - (i == 0));
            ret %= mod;
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
