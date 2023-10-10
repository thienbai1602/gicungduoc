#include    <bits/stdc++.h>
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
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 5e4 + 66;

int N, K;

bool check(vector<ll>& x, ll R)
{
    ll st = x[0], cnt = 1;
    for(int i=1; i<N; i++)
    {
        if (st + 2 * R < x[i])
        {
            st = x[i];
            ++cnt;
        }
    }
    return cnt <= K;
}

ll bs(vector<ll> &x, ll l, ll r)
{
    ll ans = -1;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (check(x, m))
        {
            ans = m;
            r = m - 1;
        } else
        {
            l = m + 1;
        }
    }
    return ans;
}

void solve()
{
    cin >> N >> K;
    vector<ll> x(N);
    for(int i=0; i<N; i++)
    {
        cin >> x[i];
    }
    sort(all(x));
    cout << bs(x, 0, 1e9);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
