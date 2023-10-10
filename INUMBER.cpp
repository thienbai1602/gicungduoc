#include    <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 1e3 + 66;

struct st
{
    vector<int> a;
    int S, tDigit;

    st(vector<int> b, int _S = 0, int _tDigit = 0)
    {
        a = b, S = _S, tDigit = _tDigit;
    }
};

int tc, N;
bool cnt[mxN][mxN];

void solve()
{
    cin >> N;
    queue<st> pq;
    memset(cnt, false, sizeof(cnt));
    for(int digit=1; digit<=9; digit++)
    {
        pq.push(st(vector<int>{digit}, digit % N, digit));
        cnt[digit % N][digit] = 1;
    }

    while(!pq.empty())
    {
        st nxt = pq.front(); pq.pop();
        ll T = nxt.S, D = nxt.tDigit;
        vector<int> cur = nxt.a;

        if (T == 0 && D == N)
        {
            for(int x : cur)
            {
                cout << x;
            }
            cout << "\n";
            return;
        }

        for(int digit=0; digit<=9; digit++)
        {
            cur.pb(digit);
            if (D + digit <= N && !cnt[(T * 10 + digit) % N][D + digit])
            {
                pq.push(st(cur, (T * 10 + digit) % N, D + digit));
                ++cnt[(T * 10 + digit) % N][D + digit];
            }
            cur.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> tc;
    while(tc--) solve();
    return 0;
}
