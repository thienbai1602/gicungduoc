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
const ll MOD = 1e6 + 7;
const int mxN = 1e6 + 66;

struct matrix
{
    ll c[2][2];
    matrix()
    {
        c[0][0] = 0;
        c[0][1] = c[1][0] = c[1][1] = 1;
    }

    matrix operator * (const matrix &v)
    {
        matrix ans;
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                ans.c[i][j] = 0;
            }
        }

        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                for(int k=0; k<2; k++)
                {
                    (ans.c[i][j] += c[i][k] * v.c[k][j]) %= MOD;
                }
            }
        }
        return ans;
    }
};

ll N;

matrix pw(matrix A, ll N)
{
    if (N == 1) return A;
    if (N & 1) return A * pw(A, N - 1);
    matrix sqr = pw(A, N / 2);
    return sqr * sqr;
}

void solve()
{
    cin >> N;
    matrix A;
    cout << pw(A, N).c[0][1] % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
