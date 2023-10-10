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

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e6 + 66;

int K, cnt[mxN];

void solve()
{
    cin >> K;
    memset(cnt, 0, sizeof(cnt));
    deque<ii> pq; pq.pb(mp(1, 1));
    while(!pq.empty())
    {
        int x = pq.front().fi, y = pq.front().se;
        pq.pop_front();

        if (x == 0)
        {
            cout << y;
            return;
        }

        if (cnt[x]) continue;
        cnt[x] = true;

        pq.push_front(mp((x * 10) % K, y));
        pq.pb(mp((x + 1) % K, y + 1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}


