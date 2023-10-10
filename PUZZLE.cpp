#include    <bits/stdc++.h>
//#define SKY
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
const int mxN = 1e6 + 66;

ll a[4], b[4], ans = -1;

ll sq(ll x)
{
    return x * x;
}

void ck(int x, int y, int z)
{
    if (a[x] == a[y] + a[z] && b[y] == b[z])
    {
        ans = max(ans, (ll)sqrt(sq(a[x]) + sq(b[x] + b[y])));
    }
}

void solve()
{
    cin >> a[0] >> b[0];
    cin >> a[1] >> b[1];
    cin >> a[2] >> b[2];
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                if (a[0] == a[1] && a[1] == a[2])
                {
                    ans = max(ans, (ll)sqrt(sq(a[0]) + sq(b[0] + b[1] + b[2])));
                } else
                {
                    ck(0, 1, 2);
                    ck(1, 0, 2);
                    ck(2, 0, 1);
                }
                swap(a[2], b[2]);
            }
            swap(a[1], b[1]);
        }
        swap(a[0], b[0]);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif //SKY
    solve();
    return 0;
}
