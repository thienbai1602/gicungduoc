#include    <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e18;

vector<vector<ll>> grid(505, vector<ll>(505));
int numRow, numCol;
ll s, K;

void solve()
{
    cin >> numRow >> numCol >> K >> s;
    for(int i=0; i<K; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        grid[u][v]++, grid[x + 1][y + 1]++;
        grid[u][y + 1]--, grid[x + 1][v]--;
    }

    for(int row=1; row<=500; row++)
    {
        for(int col=1; col<=500; col++)
        {
            grid[row][col] += grid[row - 1][col] + grid[row][col - 1] - grid[row - 1][col - 1];
        }
    }

    ll atm = 0;
    vector<vector<ll>> pref(505, vector<ll>(505, 0));
    for(int row=1; row<=numRow; row++)
    {
        for(int col=1; col<=numCol; col++)
        {
            if (grid[row][col] == s)
            {
                pref[row][col]--;
                atm++;
            } else
            {
                if (grid[row][col] == s - 1)
                {
                    pref[row][col]++;
                }
            }
        }
    }

    for(int row=1; row<=numRow; row++)
    {
        for(int col=1; col<=numCol; col++)
        {
            pref[row][col] += pref[row - 1][col] + pref[row][col - 1] - pref[row - 1][col - 1];
        }
    }

    ll tp = -INF;
    for(int row_top=1; row_top<=numRow; row_top++)
    {
        for(int row_bottom=row_top; row_bottom<=numRow; row_bottom++)
        {
            ll mi = 0;
            for(int col=1; col<=numCol; col++)
            {
                ll cur = pref[row_bottom][col] - pref[row_top - 1][col] - pref[row_bottom][0] + pref[row_top - 1][0];
                tp = max(tp, cur - mi);
                mi = min(mi, cur);
            }
        }
    }
    cout << tp + atm;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
