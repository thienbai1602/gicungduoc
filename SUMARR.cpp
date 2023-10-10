#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 166;

int numRow, numCol, Q;
ll table[mxN][mxN];

void solve()
{
    cin >> numRow >> numCol >> Q;
    for(int i=1; i<=numRow; i++)
    {
        for(int j=1; j<=numCol; j++)
        {
            cin >> table[i][j];
        }
    }

    for(int i=1; i<=numRow; i++)
    {
        for(int j=1; j<=numCol; j++)
        {
            table[i][j] += table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1];
        }
    }

    while(Q--)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << table[u][v] - table[u][y - 1] - table[x - 1][v] + table[x - 1][y - 1] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("SUMARR.INP", "r", stdin);
    freopen("SUMARR.OUT", "w", stdout);
    solve();
    return 0;
}
