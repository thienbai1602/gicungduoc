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
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1 << 20 + 5;

int n, k;

void solve()
{
    cin >> n >> k;
    vector<ll> f(1 << n + 1, 0);
    for(int i=0; i<(1 << n); i++)
    {
        cin >> f[i];
    }

    for(int day=1; day<=k; day++)
    {
        vector<ll> cur(1 << n + 1, 0);
        for(int i=0; i<(1 << n); i++)
        {
            for(int j=0; j<(1 << n); j++)
            {
                if (i == j) continue;
                //cout << j << " " << i << " " << (f[i] * (2 * (i | j) - i - j)) % MOD << "\n";
                (cur[j] += f[i] * (2 * (i | j) - i - j)) %= MOD;
            }
        }

        for(int i=0; i<(1 << n); i++)
        {
            f[i] = cur[i];
        }
    }

    for(int i=0; i<(1 << n); i++)
    {
        cout << f[i] << " ";
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
