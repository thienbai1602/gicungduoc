#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mxN = 66;

int numRow, numCol, K, grid[mxN][mxN];

void solve()
{
    cin >> numRow >> numCol >> K;
    for(int i=0; i<numRow; i++)
    {
        for(int j=0; j<numCol; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> res(numRow);
    for(int i=0; i<numRow; i++)
    {
        res[i].resize(numCol);
    }

    for(int u=0, d=numRow-1, l=0, r=numCol-1; u<=d && l<=r; u++, d--, l++, r--)
    {
        vector<ii> a;
        for(int i=u; i<=d; i++)
        {
            a.push_back(mp(i, l));
        }

        for(int i=l+1; i<=r-1; i++)
        {
            a.push_back(mp(d, i));
        }

        for(int i=d; i>=u; i--)
        {
            a.push_back(mp(i, r));
        }

        for(int i=r-1; i>=l+1; i--)
        {
            a.push_back(mp(u, i));
        }

        int sz = (int)a.size();
        int cyc = K % sz;
        for(int i=0; i<sz; i++)
        {
            int x = a[i].fi, y = a[i].se;
            int nextX = a[(i + cyc) % sz].fi, nextY = a[(i + cyc) % sz].se;
            res[nextX][nextY] = grid[x][y];
        }
    }

    for(int i=0; i<numRow; i++)
    {
        for(int j=0; j<numCol; j++)
        {
            cout << res[i][j] << (j < numCol - 1 ? " " : "\n");
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
