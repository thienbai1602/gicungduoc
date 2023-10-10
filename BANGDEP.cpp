#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int numRow, numCol;

void solve()
{
    cin >> numRow >> numCol;
    vector<vector<ll>> table(numRow + 1, vector<ll>(numCol + 1, 0));
    for(int i=1; i<=numRow; i++)
    {
        for(int j=1; j<=numCol; j++)
        {
            cin >> table[i][j];
        }
    }

    vector<vector<ll>> pref(numRow + 1, vector<ll>(numCol + 1, 0));
    for(int row=1; row<=numRow; row++)
    {
        for(int col=1; col<=numCol; col++)
        {
            pref[row][col] = pref[row - 1][col] + pref[row][col - 1] + table[row][col] - pref[row - 1][col - 1];
        }
    }

    ll ret = 0;
    for(int row_top=1; row_top<=numRow; row_top++)
    {
        for(int row_bottom=row_top; row_bottom<=numRow; row_bottom++)
        {
            vector<int> cnt(9, 0); cnt[0] = 1;
            for(int col=1; col<=numCol; col++)
            {
                ll tp = pref[row_bottom][col] - pref[row_top - 1][col] - pref[row_bottom][0] + pref[row_top - 1][0];
                ret += cnt[tp % 9]++;
            }
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
