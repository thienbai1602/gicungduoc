#include    <bits/stdc++.h>
#define ll long long
using namespace std;

int numRow, numCol, K;

void solve()
{
    cin >> numRow >> numCol >> K;
    vector<int> row(numRow + 1, 0), col(numCol + 1, 0);
    for(int i=0; i<K; i++)
    {
        int u, v;
        cin >> u >> v;
        //cout << u << " " << v << "\n";
        row[u] = 1, col[v] = 1;
    }

    ll numberRow = 0, numberCol = 0;
    for(int i=1; i<=numRow; i++)
    {
        numberRow += !row[i];
        //cout << i << " " << row[i] << "\n";
    }

    for(int i=1; i<=numCol; i++)
    {
        numberCol += !col[i];
        //cout << i << " " << col[i] << "\n";
    }
    ll ret = numberRow * numCol + numberCol * (numRow - numberRow);
    cout << numRow * numCol - ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
