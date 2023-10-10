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
const int mxN = 1e5 + 66;

int N;
ll a[mxN], pref[mxN];
map<ll, vector<int>> store;

void solve()
{
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cin >> a[i];
    }

    set0(pref);
    for(int i=1; i<=N; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    store[0].pb(0);
    vector<ll> seg;
    for(int i=1; i<=N; i++)
    {
        store[pref[i]].pb(i);
        seg.pb(pref[i]);
    }

    sort(all(seg));
    seg.erase(unique(all(seg)), seg.end());

    vector<ll> ans(N + 2, 0);
    for(int i=0; i<sz(seg); i++)
    {
        ll nxt = seg[i];
        vector<int> todo = store[nxt];
        ll a = sz(todo) - 1, b = 1;
        for(int i=0; i<sz(todo)-1; i++)
        {
            ans[todo[i] + 1] += a * b;
            ans[todo[i + 1] + 1] -= a * b;
            a--, b++;
        }
    }

    for(int i=1; i<=N; i++)
    {
        ans[i] += ans[i - 1];
        cout << ans[i] << " ";
    }
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
