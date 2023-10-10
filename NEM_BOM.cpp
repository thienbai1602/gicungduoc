#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e3 + 66;

ll N, M, maxR = -INF, maxC = -INF, minR = INF, minC = INF;
ll grid[mxN][mxN], pref[mxN][mxN];
bool sf[mxN][mxN];

ll S(int u, int v, int K)
{
    ll lu = u - K, lv = v - K;
    ll ru = u + K, rv = v + K;
    if (lu < minR || lv < minC || lu > maxR || lv > maxC || (sf[lu][lv] * sf[ru][rv] * sf[lu][rv] * sf[ru][lv] == 0)) return -INF;
     else return pref[ru][rv] - pref[ru][lv - 1] - pref[lu - 1][rv] + pref[lu - 1][lv - 1];
}

void solve()
{
    cin >> N >> M;
    int flat = max(N, M) + 1;
    memset(sf, false, sizeof(sf));
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            ll u = i - j + flat, v = i + j;
            maxR = max(maxR, u);
            maxC = max(maxC, v);
            minR = min(minR, u);
            minC = min(minC, v);
            cin >> grid[u][v];
            sf[u][v] = 1;
        }
    }

    set0(pref);
    for(int i=minR; i<=maxR+1; i++)
    {
        for(int j=minC; j<=maxC+1; j++)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + grid[i][j];
        }
    }

    ll ans = -INF;
    for(int K=0; K<=min(N, M); K++)
    {
        for(int i=1; i<=N-K; i++)
        {
            for(int j=1; j<=M-K; j++)
            {
                int u = i - j + flat, v = i + j;
                ans = max(ans, S(u, v, K));
            }
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
