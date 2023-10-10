#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 22;
const ll MOD = 1e9 + 7;

int N;
bool can[mxN][mxN];
ll dp[(1 << mxN)][mxN];

void solve()
{
    //clock_t time_req;
    //time_req = clock();
    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> can[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    for(int j=0; j<N; j++)
    {
        if (can[0][j]) dp[1LL << j][0] = 1;
    }

    for(int j=1; j<N; j++)
    {
        for(ll mask=0; mask<(1 << N); mask++)
        {
            if (__builtin_popcount(mask) > j) continue;
            for(int k=0; k<N; k++)
            {
                if (!can[j][k] || !dp[mask][j - 1] || (mask >> k) & 1) continue;
                ll new_mask = mask | (1LL << k);
                dp[new_mask][j] = (dp[new_mask][j] + dp[mask][j - 1]) % MOD;
            }
        }
    }
    cout << dp[(1 << N) - 1][N - 1] % MOD;
    //time_req = clock() - time_req;
    //cout << "\n" << (float)time_req / CLOCKS_PER_SEC << " ms";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
