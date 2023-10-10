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
#define rall(x) x.rbegin(), x.rend()
#define set0(d) memset(d, 0, sizeof(d))
using namespace std;

const int LOG = 20;
const int base = 311;
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 2e5 + 66;

ll T;
int n;
vector<pair<ii, int>> exam;

pair<vector<int>, bool> ck(int X)
{
    multiset<ii> store;
    for(int i=0; i<n; i++)
    {
        if (exam[i].fi.fi >= X)
        {
            store.insert(mp(exam[i].fi.se, exam[i].se));
        }
    }

    ll cur = T;
    int cnt = 0;
    vector<int> seg;
    while(!store.empty()&& cnt < X)
    {
        ii tp = *store.begin();
        store.erase(store.find(*store.begin()));
        if (tp.fi > cur) break;
        cur -= tp.fi;
        ++cnt;
        seg.pb(tp.se);
    }
    return mp(seg, cnt >= X);
}

void solve()
{
    cin >> n >> T;
    exam.assign(n, mp(mp(0, 0), 0));
    for(int i=0; i<n; i++)
    {
        cin >> exam[i].fi.fi >> exam[i].fi.se;
        exam[i].se = i;
    }

    vector<int> ret;
    int l = 0, r = n, ans = 0;
    while(l <= r)
    {
        int m = (l + r) >> 1;
        pair<vector<int>, bool> nxt = ck(m);
        if (nxt.se)
        {
            ans = m;
            l = m + 1;
            ret = nxt.fi;
        } else
        {
            r = m - 1;
        }
    }

    cout << ans << "\n" << sz(ret) << "\n";
    for(int &x : ret) cout << x + 1 << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
