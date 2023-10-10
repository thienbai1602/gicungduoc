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
const int mxN = 1e6 + 66;

ll N, M, T, freq[mxN];

void solve()
{
    cin >> N >> M >> T;
    for(int i=0; i<M; i++)
    {
        freq[i] = (N / M) + (i > 0 ? (N % M >= i) : 0);
    }

    for(int i=0; i<M; i++)
    {
        if (T > freq[i])
        {
            T -= freq[i];
        } else
        {
            cout << (ll)((i == 0 ? M : i) + M * (T - 1));
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
