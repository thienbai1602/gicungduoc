#include    <bits/stdc++.h>
#define ll unsigned long long
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
const int block = 800;
const ll MOD = 1e9 + 7;
const int mxN = 2e5 + 66;
const int mxK = 1e6 + 66;

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

ll K = 0, cnt[mxK];
int n, Q, a[mxN];

void add(int x)
{
    K -= cnt[x] * cnt[x] * x;
    ++cnt[x];
    K += cnt[x] * cnt[x] * x;
}

void del(int x)
{
    K -= cnt[x] * cnt[x] * x;
    --cnt[x];
    K += cnt[x] * cnt[x] * x;
}

void solve()
{
    cin >> n >> Q;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    vector<query> listID;
    for(int i=0; i<Q; i++)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        listID.pb(query(l, r, i));
    }
    sort(all(listID));

    set0(cnt);
    vector<ll> ans(Q);
    int L = 0, R = -1;
    for(auto [l, r, idx] : listID)
    {
        while(L < l)
        {
            del(a[L++]);
        }

        while(R > r)
        {
            del(a[R--]);
        }

        while(R < r)
        {
            add(a[++R]);
        }

        while(L > l)
        {
            add(a[--L]);
        }
        ans[idx] = K;
    }

    for(ll &x : ans)
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
