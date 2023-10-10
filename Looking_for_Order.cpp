#include    <bits/stdc++.h>
#define ll int
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const ll INF = 1e17;
const int mxN = 25;

int n;
ii coord[mxN];
ll val[mxN][mxN], dp[1 << 24], tv[1 << 24];

ll sq(ll x)
{
    return x * x;
}

void solve()
{
    cin >> coord[0].fi >> coord[0].se >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> coord[i].fi >> coord[i].se;
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            val[i][j] = sq(coord[i].fi - coord[j].fi) + sq(coord[i].se - coord[j].se);
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(ll mask=0; mask<(1 << n); mask++)
    {
        for(int i=0; i<n; i++)
        {
            if ((mask >> i) & 1) continue;
            for(int j=i; j<n; j++)
            {
                if ((mask >> j) & 1) continue;
                ll new_mask = mask | (1 << i) | (1 << j);
                ll nxt = dp[mask] + val[0][i + 1] + val[i + 1][j + 1] + val[j + 1][0];
                if (nxt < dp[new_mask])
                {
                    dp[new_mask] = nxt;
                    tv[new_mask] = mask;
                }
            }
            break;
        }
    }

    cout << dp[(1 << n) - 1] <<  "\n0 ";
    ll mask = (1 << n) - 1;
    while(mask != 0)
    {
        ll cur_item = tv[mask] ^ mask;
        for(int i=0; i<n; i++)
        {
            if ((cur_item >> i) & 1) cout << i + 1 << " ";
        }
        cout << "0 ";
        mask = tv[mask];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
