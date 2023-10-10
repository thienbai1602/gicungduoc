#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mxN = 20;
const ll INF = 1e17;

struct state
{
    ll height, weight, strength;
};

ll H;
int n;
ii dp[1 << mxN];
state cow[mxN];

void solve()
{
    cin >> n >> H;
    for(int i=0; i<n; i++)
    {
        cin >> cow[i].height >> cow[i].weight >> cow[i].strength;
    }

    fill(dp, dp + (1 << n), mp(0, -1));
    dp[0] = mp(0, INF);
    for(ll mask=0; mask<(1LL << n); mask++)
    {
        for(int j=0; j<n; j++)
        {
            if (!((mask >> j) & 1))
            {
                ll new_mask = mask | (1 << j);
                //cout << mask << " " << j << " " << new_mask << "\n";
                dp[new_mask].fi += cow[j].height;
                dp[new_mask].se = max(dp[new_mask].se, min(dp[mask].se - cow[j].weight, cow[j].strength));
            }
        }
    }

    ll max_sf = -1;
    for(ll mask=0; mask<(1LL << n); mask++)
    {
        if (dp[mask].fi >= H) max_sf = max(max_sf, dp[mask].se);
    }

    if (max_sf == -1)
    {
        cout << "Mark is too tall";
    } else
    {
        cout << max_sf;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    solve();
    return 0;
}
