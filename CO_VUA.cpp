#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 13;

int N, K;
vector<ll> store;
vector<vector<int>> adj;
ll dp[mxN][1 << mxN][mxN * mxN];

bool sf(ll x, ll y)
{
    for(int k=N-1; k>=0; k--)
    {
        if (((x >> k) & 1) == 0) continue;
        for(int z=max(0, k-1); z<=min(N-1, k+1); z++)
        {
            if ((y >> z) & 1) return false;
        }
    }
    return true;
}

void solve()
{
    cin >> N >> K;
    for(ll mask=0; mask<(1 << N); mask++)
    {
        bool f = true;
        int cnt = 0;
        for(int k=0; k<N; k++)
        {
            if ((mask >> k) & 1) ++cnt;
             else cnt = 0;
            if (cnt > 1)
            {
                f = false;
                break;
            }
        }
        if (f) store.pb(mask);
    }

    adj.resize(sz(store));
    for(int i=0; i<sz(store); i++)
    {
        for(int j=0; j<sz(store); j++)
        {
            if (sf(store[i], store[j]))
            {
                adj[i].pb(j);
            }
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for(int row=1; row<=N; row++)
    {
       for(int i=0; i<sz(store); i++)
        {
            ll mask = store[i];
            int cur = __builtin_popcount(mask);
            for(int king=cur; king<=K; king++)
            {
                for(int j : adj[i])
                {
                    ll prev = store[j];
                    dp[row][mask][king] += dp[row - 1][prev][king-cur];
                }
            }
        }
    }

    unsigned ll ans = 0;
    for(ll mask : store)
    {
        ans += dp[N][mask][K];
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
