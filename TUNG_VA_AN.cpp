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
const int mxN = 1e6 + 66;

int numRow, numCol, K, freq[mxN];

void solve()
{
    cin >> numRow >> numCol >> K;
    for(int r=0; r<numRow; r++)
    {
        for(int c=0; c<numCol; c++)
        {
            ll x;
            cin >> x;
            ++freq[x];
        }
    }

    vector<ll> store;
    for(int i=1; i<=(int)1e5; i++)
    {
        store.pb(freq[i]);
    }

    sort(all(store), greater<ll>());
    ll ans = 0, id = 0;
    while(K--)
    {
        ans += store[id++];
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
