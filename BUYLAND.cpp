#include    <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll K;
int numRow, numCol;
vector<vector<ll>> land;

ll s(int x, int y, int z, int t)
{
    return land[z][t] - land[z][y - 1] - land[x - 1][t] + land[x - 1][y - 1];
}

void solve()
{
    cin >> numRow >> numCol >> K;
    land.resize(numRow + 1, vector<ll>(numCol + 1, 0));
    for(int i=1; i<=numRow; i++)
    {
        for(int j=1; j<=numCol; j++)
        {
            cin >> land[i][j];
        }
    }

    for(int row=1; row<=numRow; row++)
    {
        for(int col=1; col<=numCol; col++)
        {
            land[row][col] += land[row - 1][col] + land[row][col - 1] - land[row - 1][col - 1];
        }
    }


    ll ret = 0;
    pair<int, int> st, ed;
    for(int row_top=1; row_top<=numRow; row_top++)
    {
        for(int row_bottom=row_top; row_bottom<=numRow; row_bottom++)
        {
            int col_left = 1;
            for(int col_right=1; col_right<=numCol; col_right++)
            {
                while(s(row_top, col_left, row_bottom, col_right) > K) col_left++;
                if ((row_bottom - row_top + 1) * (col_right - col_left + 1) > ret)
                {
                    ret = (row_bottom - row_top + 1) * (col_right - col_left + 1);
                    st = {row_top, col_left}, ed = {row_bottom, col_right};
                }
            }
        }
    }
    cout << ret << "\n" << st.fi << " " << st.se << " " << ed.fi << " " << ed.se;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
