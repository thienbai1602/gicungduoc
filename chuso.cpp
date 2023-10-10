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
const int mxN = 1e6 + 66;

int tc;
ll a, b, L, R;

struct matrix
{
    ll c[2][2];
    matrix()
    {
        c[0][0] = 0;
        c[0][1] = c[1][0] = c[1][1] = 1;
    }

    matrix operator * (matrix v)
    {
        matrix res;
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                res.c[i][j] = 0;
            }
        }

        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                for(int k=0; k<2; k++)
                {
                    res.c[i][j] = (res.c[i][j] + c[i][k] * v.c[k][j]) % 10;
                }
            }
        }
        return res;
    }
};

matrix pw(matrix A, ll n)
{
    if (n == 1) return A;
    if (n & 1) return A * pw(A, n - 1);
    matrix tmp = pw(A, n / 2);
    return tmp * tmp;
}

void solve()
{
    cin >> a >> b >> L >> R;
    /*vector<ll> fibo(1e6 + 5);
    fibo[1] = a % 10, fibo[2] = b % 10;
    ll ans = 0;
    for(ll x=3; x<=R; x++)
    {
        fibo[x] = (fibo[x - 1] + fibo[x - 2]) % 10;
    }

    for(ll x=L; x<=R; x++)
    {
        ans = (ans + fibo[x]) % 10;
    }
    cout << ans << "\n";*/

    matrix A;
    /*ll x, y, z;
    if (L <= 3)
    {
        if (L == 1)
        {
            x = 0;
            y = a % 10;
        } else if (L == 2)
        {
            x = a % 10, y = b % 10;
        } else
        {
            x = b % 10, y = (a + b) % 10;
        }
    } else
    {
        ll u = pw(A, L - 2).c[0][1], v = pw(A, L - 1).c[0][1], s = (L == 3 ? 0 : pw (A, L - 3).c[0][1]);
        x = ((s * a) % 10 + (u * b) % 10) % 10, y = ((u * a) % 10 + (v * b) % 10) % 10;
    }

    //cout << x << " " << y << "\n";

    ll ans = y % 10;
    for(ll k=L+1; k<=R; k++)
    {
        z = (k == 2 ? b : (x + y)) % 10;
        ans = (ans + z) % 10;
        x = y % 10, y = z % 10;
    }
    cout << ans % 10 << "\n";*/
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
