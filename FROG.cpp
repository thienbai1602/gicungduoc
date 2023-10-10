#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int mxN = 1e3 + 66;

deque<int> dq;
int numRow, numCol, K;
ll a[mxN][mxN], dp[mxN][mxN];

void push(int row, int id)
{
    while(!dq.empty() && dp[row - 1][id] >= dp[row - 1][dq.back()]) dq.pop_back();
    dq.pb(id);
}

void pop(int id)
{
    if (!dq.empty() && dq.front() == id) dq.pop_front();
}

void solve()
{
    cin >> numRow >> numCol >> K;
    for(int row=1; row<=numRow; row++)
    {
        for(int col=1; col<=numCol; col++)
        {
            cin >> a[row][col];
        }
    }

    memset(dp, 0, sizeof(dp));
    for(int col=1; col<=numCol; col++)
    {
        dp[1][col] = a[1][col];
    }

    for(int row=2; row<=numRow; row++)
    {
        int upCol = 0;
        dq.clear();
        while(upCol < K)
        {
            push(row, ++upCol);
        }

        for(int col=1; col<=numCol; col++)
        {
            if (upCol + col <= numCol) push(row, upCol + col);
            dp[row][col] = a[row][col] + dp[row - 1][dq.front()];
            if (col > K) pop(col - K);
        }
    }

    ll ans = 0;
    for(int col=1; col<=numCol; col++)
    {
        ans = max(dp[numRow][col], ans);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}


