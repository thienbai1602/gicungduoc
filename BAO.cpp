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
const int mxN = 6e3 + 66;

int N, ocean[mxN][mxN];

void upd(int u, int v, int x)
{
    int lu = max(1, u - x), lv = max(1, v - x);
    int ru = min(2*N-1, u + x), rv = min(2*N , v + x);
    ++ocean[lu][lv], --ocean[lu][rv + 1];
    ocean[ru + 1][lv]--, ocean[ru + 1][rv + 1]++;
}

void solve()
{
    cin >> N;
    set0(ocean);
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            int u, v, x;
            cin >> x;
            u = i - j + N, v = i + j;
            if (x > 0)
            {
                upd(u, v, x);
            }
        }
    }

    for(int i=1; i<=2*N; i++)
    {
        for(int j=1; j<=2*N; j++)
        {
            ocean[i][j] += ocean[i - 1][j] + ocean[i][j - 1] - ocean[i - 1][j - 1];
        }
    }

    ll ans = N * N;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            int u = i - j + N, v = i + j;
            ans -= (ocean[u][v] > 0);
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
