#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 105;
const ll INF = ;

int n, m, K;

struct matrix
{
    ll c[mxN][mxN];
    matrix()
    {
        for(int i=0; i<mxN; i++)
        {
            for(int j=0; j<mxN; j++)
            {
                c[i][j] = INF;
            }
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
                    res.c[i][j] = min(res.c[i][j], c[i][k] + v.c[k][j]);
                }
            }
        }
        return res;
    }
}I;

matrix pw(matrix A, ll N)
{
    if (N == 0)
    {
        return I;
    }

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
        ll u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        A.c[u][v] = min(A.c[u][v], w);
    }
    A = pw(A, K);
    cout << (A.c[0][n - 1] >= INF ? -1 : A.c[0][n - 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
