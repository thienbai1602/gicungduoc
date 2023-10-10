#include    <bits/stdc++.h>
//#define SKY
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e3 + 66;

int numRow, numCol, K, a[mxN][mxN], p[mxN][mxN];

void solve()
{
    cin >> numRow >> numCol >> K;
    for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            cin >> a[r][c];
        }
    }

    for(int r=1; r<=numRow; r++)
    {
        deque<int> pq;
        for(int c=1; c<=numCol; c++)
        {
            while(!pq.empty() && a[r][pq.back()] >= a[r][c]) pq.pop_back();
            pq.pb(c);
            if (pq.front() <= c - K) pq.pop_front();
            if (!pq.empty() && c >= K) p[r][c] = a[r][pq.front()];
        }
    }

    /*for(int r=1; r<=numRow; r++)
    {
        for(int c=1; c<=numCol; c++)
        {
            cout << p[r][c] << (c < numCol ? " " : "\n");
        }
    }*/

    int ans = -1;
    for(int c=K; c<=numCol; c++)
    {
        deque<int> pq;
        for(int r=1; r<=numRow; r++)
        {
            while(!pq.empty() && p[pq.back()][c] >= p[r][c]) pq.pop_back();
            pq.pb(r);
            if (pq.front() <= r - K) pq.pop_front();
            if (!pq.empty() && r >= K) ans = max(ans, p[pq.front()][c]);
        }
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef SKY
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif //SKY
    solve();
    return 0;
}
