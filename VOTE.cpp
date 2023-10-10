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
const int mxN = 1e5 + 66;

int n, sl = 0;
ll x[mxN], y[mxN], candi[mxN];

bool sf(int K, ll X)
{
    multiset<ll> store, tp[n + 1];
    for(int i=0; i<n; i++)
    {
        store.insert(y[i]);
        tp[x[i]].insert(y[i]);
    }

    ll S = 0;
    int curSz = sl;
    for(int i=2; i<=n; i++)
    {
        int sz = candi[i];
        while(sz >= K)
        {
            --sz;
            ++curSz;
            S += *tp[i].begin();
            auto it = store.lower_bound(*tp[i].begin());
            store.erase(it);
            it = tp[i].lower_bound(*tp[i].begin());
            tp[i].erase(it);
        }
    }

    while(curSz < K)
    {
        ++curSz;
        S += *store.begin();
        store.erase(store.begin());
    }
    return S <= X;
}

bool check(ll X)
{
    int l = 0, r = (n + 1) >> 1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if (sf(mid, X))
        {
            return true;
        } else
        {
            l = mid + 1;
        }
    }
    return false;
}

ll bs(ll l, ll r)
{
    int ans = 0;
    while(l <= r)
    {
        ll m = (l + r) >> 1;
        if (check(m))
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
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> x[i] >> y[i];
        candi[x[i]]++;
    }
    cout << bs(0, 1e11);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    solve();
    return 0;
}
