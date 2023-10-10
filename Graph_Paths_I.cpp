#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
const int mxN = 105;

int n, m, K;

struct matrix
{
    ll c[mxN][mxN];
    matrix()
    {
        for(int i=0; i<mxN; i++)
        {
            memset(c[i], 0, sizeof(c[i]));
        }
    }

    matrix operator * (matrix const& v)
    {
        matrix res;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                {
                    res.c[i][j] = (res.c[i][j] + c[i][k] * v.c[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

matrix pw(matrix A, ll N)
{
    if (N == 1)
    {
        return A;
    }

    if (N & 1)
    {
        return A * pw(A, N - 1);
    }
    matrix tp = pw(A, N / 2);
    return tp * tp;
}

void solve()
{
    cin >> n >> m >> K;
    matrix A;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        A.c[u][v]++;
    }
    A = pw(A, K);
    cout << A.c[0][n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
