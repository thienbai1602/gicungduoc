#include    <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 3e4 + 66;

struct Query
{
    ll u, v, id, val;

    Query(ll _id = 0, ll _u = 0, ll _v = 0, ll _val = 0)
    {
        id = _id, u = _u, v = _v, val = _val;
    }

    bool operator < (const Query &q)
    {
        return val < q.val;
    }
};

int n, Q;
ii a[mxN];
ll fen[mxN];
vector<Query> q;

void upd(int id)
{
    for(; id<=n; id+=(id & -id))
    {
        fen[id]++;
    }
}

int get(int id)
{
    int ret = 0;
    for(; id>0; id-=(id & -id))
    {
        ret += fen[id];
    }
    return ret;
}

void solve()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }

    cin >> Q;
    for(int i=0; i<Q; i++)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        q.pb(Query(i, l, r, x));
    }

    sort(all(q));
    sort(a + 1, a + 1 + n);

    ll pos = n;
    vector<ll> ans(Q);
    for(; Q>0; Q--)
    {
        while(pos > 0 && a[pos].fi > q[Q - 1].val)
        {
            upd(a[pos--].se);
        }
        ans[q[Q - 1].id] = get(q[Q - 1].v) - get(q[Q - 1].u - 1);
    }

    for(int i=0; i<sz(ans); i++)
    {
        cout << ans[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
