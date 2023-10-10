#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 111539786;

struct matrix
{
    ll c[2][2];

    matrix()
    {
        c[0][0] = 0;
        c[0][1] = c[1][0] = c[1][1] = 1;
    }

    matrix operator * (const matrix& v)
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
                    res.c[i][j] = (res.c[i][j] + c[i][k] * v.c[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

int tc;
ll N;

matrix pw(matrix A, ll N)
{
    if (N == 1) return A;
    if (N % 2 == 1)
    {
        return A * pw(A, N - 1);
    }

    matrix t = pw(A, N / 2);
    return t * t;
}

void solve()
{
    cin >> N;
    matrix A;
    A = pw(A, N + 1);
    cout << A.c[0][1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}
