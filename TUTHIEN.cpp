#include    <bits/stdc++.h>
#define ll long long
#define ld long double
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

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

int N, Q, block = 0;
bool state[2][mxN];

void solve()
{
    cin >> N >> Q;
    memset(state, false, sizeof(state));
    for(int i=0; i<Q; i++)
    {
        int x, y;
        cin >> x >> y;
        --x;
        if (state[x][y])
        {
            state[x][y] = false;
            for(int k=max(1, y-1); k<=min(N-1, y+1); k++)
            {
                if (state[!x][k])
                {
                    --block;
                }
            }
        } else
        {
            state[x][y] = true;
            for(int k=max(1, y-1); k<=min(N-1, y+1); k++)
            {
                if (state[!x][k])
                {
                    ++block;
                }
            }
        }
        cout << (!block ? "YES\n" : "NO\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
