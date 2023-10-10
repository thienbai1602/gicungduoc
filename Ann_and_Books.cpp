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
const ll inf = 1e18;
const int block = 400;
const ll MOD = 1e9 + 7;
const int mxN = 1e5 + 66;

struct query
{
    int l, r, id;
    query(int _l = 0, int _r = 0, int _id = 0)
    {
        l = _l, r = _r, id = _id;
    }

    bool operator < (const query& Q)
    {

        return mp(l / block, r) < mp(Q.l / block, Q.r);
    }
};

ll a[mxN], pref[mxN], K, cnt = 0;
vector<ll> compress;
int n, Q, t[mxN];

int get(ll X)
{
    return lower_bound(all(compress), X) - compress.begin();
}

void solve()
{
    cin >> n >> K;
    for(int i=1; i<=n; i++)
    {
        cin >> t[i];
    }

    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        a[i] *= (t[i] == 1 ? 1 : -1);
    }

    set0(pref);
    for(int i=1; i<=n; i++)
    {
        pref[i] = a[i] + pref[i - 1];
        compress.pb(pref[i]);
        compress.pb(pref[i] + K);
        compress.pb(pref[i] - K);
    }
    compress.pb(0), compress.pb(-K), compress.pb(K);
    sort(all(compress));
    compress.erase(unique(all(compress)), compress.end());

    vector<vector<int>> pos(n + 1, vector<int>(3));
    for(int i=0; i<=n; i++)
    {
        pos[i][0] = get(pref[i]);
        pos[i][1] = get(pref[i] + K);
        pos[i][2] = get(pref[i] - K);
    }

    cin >> Q;
    vector<query> listID;
    for(int i=0; i<Q; i++)
    {
        int l, r;
        cin >> l >> r;
        --l;
        listID.pb(query(l, r, i));
    }
    sort(all(listID));

    vector<ll> ans(Q), store(sz(compress) + 2, 0);
    int L = listID[0].l, R = L - 1;
    for(auto [l, r, idx] : listID)
    {
        while(L < l)
        {
            --store[pos[L][0]];
            cnt -= store[pos[L][1]];
            ++L;
        }

        while(R < r)
        {
            ++R;
            cnt += store[pos[R][2]];
            ++store[pos[R][0]];
        }

        while(L > l)
        {
            --L;
            cnt += store[pos[L][1]];
            store[pos[L][0]]++;
        }

        while(R > r)
        {
            store[pos[R][0]]--;
            cnt -= store[pos[R][2]];
            R--;
        }
        ans[idx] = cnt;
    }

    for(auto &x : ans)
    {
        cout << x << "\n";
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
