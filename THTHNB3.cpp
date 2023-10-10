#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;

const int mxN = 3e3 + 66;

ll N;
vector<ii> seg;
ll ocean[mxN][mxN];
short table[mxN * 2][mxN * 2];

void solve()
{
    cin >> N;
    for(int row=1; row<=N; row++)
    {
        for(int col=1; col<=N; col++)
        {
            cin >> ocean[row][col];
            if (ocean[row][col]) seg.pb(mp(row, col));
        }
    }

    for(int row=1, tp=0; row<N; row++, tp++)
    {
        for(int col=1; col<N; col++)
        {
            table[row + col - 1][N - 2 * row + col] = ocean[row][col];
        }
    }

    for(auto [x, y] : seg)
    {
        ll v = ocean[x][y];
        table[max(0LL, x + y - 1 - v)][max(0LL, N - 2*x + y - v)]++;
        table[min(N, x + y + v)][min(N, N - 2*x + y + v + 1)]++;
        table[min(N, x + y + v)][max(0LL, N - 2*x + y - v)]--;
        table[max(0LL, x + y - 1 - v)][min(N, N - 2*x + y + v + 1)]--;
        cout << x << " " << y << " " << x + y - 1 - v << " " << N - 2*x + y - v;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
