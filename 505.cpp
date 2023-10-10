#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e9;
const int mxN = 1e6 + 66;

int numRow, numCol;
ll dp[mxN][1 << 3], mat[mxN][3];

int bit(ll x, ll k)
{
    return (x >> k) & 1;
}

void solve()
{
    cin >> numRow >> numCol;
    for(int row=0; row<numRow; row++)
    {
        string S;
        cin >> S;
        for(int col=0; col<numCol; col++)
        {
            mat[col][row] = (S[col] - '0');
        }
    }

    if (numRow == 1)
    {
        cout << 0;
        return;
    }

    if (numRow >= 4)
    {
        cout << -1;
        return ;
    }

    for(int col=1; col<=numCol; col++)
    {
        for(int row=0; row<(1 << numRow); row++)
        {
            dp[col][row] = INF;
        }
    }

    for(int col=0; col<numCol; col++)
    {
        ll mask = 0;
        for(int row=0; row<numRow; row++)
        {
            mask += (mat[col][row] * (1 << row));
        }

        for(int pre_mask=0; pre_mask<(1 << numRow); pre_mask++)
        {
            for(int new_mask=0; new_mask<(1 << numRow); new_mask++)
            {
                ll cost = __builtin_popcount(mask ^ new_mask);
                ll ncost = dp[col][pre_mask] + cost;

                bool flat = true;
                for(int p=0; p+1<numRow; p++)
                {
                    int ct = bit(pre_mask, p) + bit(pre_mask, p + 1) + bit(new_mask, p) + bit(new_mask, p + 1);
                    if (ct % 2 == 0) flat = false;
                }

                if (flat) dp[col + 1][new_mask] = min(dp[col + 1][new_mask], ncost);
            }
        }
    }

    ll ans = INF;
    for(int mask=0; mask<(1 << numRow); mask++)
    {
        ans = min(ans, dp[numCol][mask]);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
